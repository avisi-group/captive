/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <engine/engine.h>

#include <loader/zimage-loader.h>
#include <loader/elf-loader.h>
#include <loader/devtree-loader.h>
#include <loader/atags-loader.h>
#include <loader/initrd-loader.h>

#include <hypervisor/config.h>
#include <hypervisor/cpu.h>
#include <hypervisor/angel-semihosting-context.h>
#include <hypervisor/linux-semihosting-context.h>
#include <hypervisor/kvm/kvm.h>
#include <hypervisor/debugging.h>

#include <platform/simbench.h>
#include <platform/user.h>
#include <platform/virt.h>

#include <simulation/insn-count.h>
#include <simulation/cache/cache-simulation.h>

#include <util/command-line.h>
#include <util/config/config.h>

#include <devices/timers/timer-manager.h>

#include <signal.h>
#include <execinfo.h>
#include <malloc.h>

DECLARE_CONTEXT(Main);

using namespace captive;
using namespace captive::engine;
using namespace captive::devices::timers;
using namespace captive::loader;
using namespace captive::hypervisor;
using namespace captive::hypervisor::kvm;
using namespace captive::platform;
using namespace captive::util;

static void handle_segv(int sig, siginfo_t *siginfo, void *ucontext)
{
	void **backtrace_buffer = (void **) calloc(64, sizeof(void *));
	char **backtrace_syms;

	fprintf(stderr, "error: seg-fault: si_addr=%p\n", siginfo->si_addr);

	int nr = backtrace(backtrace_buffer, 64);
	fprintf(stderr, "backtrace: %d frames\n", nr);

	backtrace_syms = backtrace_symbols(backtrace_buffer, nr);
	if (backtrace_syms) {
		for (int i = 0; i < nr; i++) {
			fprintf(stderr, "[%02d] %s\n", i, backtrace_syms[i]);
		}
	}

	exit(1);
}

static Guest *current_guest;

static void handle_intr(int sig, siginfo_t *siginfo, void *ucontext)
{
	fprintf(stderr, "*** received SIGINT\n");
	if (current_guest) {
		current_guest->stop();
	}
}

static void handle_usr(int sig, siginfo_t *siginfo, void *ucontext)
{
	switch (sig) {
	case SIGUSR1:
		if (current_guest) {
			current_guest->debug_interrupt(0);
		}
		break;
	case SIGUSR2:
		if (current_guest) {
			current_guest->debug_interrupt(1);
		}
		break;
	}
}

static void init_signals()
{
	struct sigaction segv_action;
	segv_action.sa_sigaction = handle_segv;
	segv_action.sa_flags = SA_SIGINFO;

	struct sigaction intr_action;
	intr_action.sa_sigaction = handle_intr;
	intr_action.sa_flags = SA_SIGINFO;

	struct sigaction usr_action;
	usr_action.sa_sigaction = handle_usr;
	usr_action.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &segv_action, NULL);
	sigaction(SIGINT, &intr_action, NULL);
	sigaction(SIGUSR1, &usr_action, NULL);
	sigaction(SIGUSR2, &usr_action, NULL);
}

int main(int argc, const char **argv)
{
	init_signals();

	util::config::Configuration cfg;

	if (!CommandLine::parse(argc, argv, cfg)) {
		CommandLine::print_usage();
		return 1;
	}

	if (cfg.print_usage) {
		CommandLine::print_usage();
		return 0;
	}

	captive::logging::configure_logging_contexts();

	// Check that KVM is supported
	if (!KVM::supported()) {
		ERROR << "KVM is not supported";
		return 1;
	}

	// Create a new hypervisor.
	Debugger *debugger = nullptr;

	// Initialise debugging (if requested)
	if (cfg.debugging) {
		debugger = new Debugger();
	}

	Hypervisor *hv = new KVM(debugger);
	if (!hv->init()) {
		if (debugger) delete debugger;

		ERROR << "Unable to initialise the hypervisor";
		return 1;
	}

	// Create the timer manager
	TimerManager timer_manager;

	auto kernel = KernelLoader::create_from_file(cfg);
	if (!kernel) {
		delete hv;

		ERROR << "Unable to detect type of guest kernel";
		return 1;
	}

	// Create the guest platform.
	Platform *pfm;

	if (cfg.platform == "simbench") {
		pfm = new Simbench(cfg, timer_manager);
	} else if (cfg.platform == "user") {
		pfm = new UserPlatform(cfg, timer_manager, kernel);
	} else if (cfg.platform == "virt") {
		pfm = new Virtual(cfg, timer_manager);
	} else {
		ERROR << "Unrecognised platform: " << cfg.platform;
		return 1;
	}

	Engine engine(cfg.arch_module);
	if (!engine.init()) {
		delete pfm;
		delete hv;

		ERROR << "Unable to initialise engine";
		return 1;
	}

	Guest *guest = hv->create_guest(engine, *pfm);
	if (!guest) {
		delete pfm;
		delete hv;

		ERROR << "Unable to create guest VM";
		return 1;
	}

	if (cfg.semihosting.has_value()) {
		if (cfg.semihosting.value() == "angel") {
			guest->attach_semihosting_context(*new AngelSemihostingContext(*guest, cfg));
		} else if (cfg.semihosting.value() == "linux") {
			guest->attach_semihosting_context(*new LinuxSemihostingContext(*guest, cfg, kernel));
		} else {
			ERROR << "Unsupported semihosting context '" << cfg.semihosting.value() << "'";
			return 1;
		}
	}

	current_guest = guest;

	// Initialise the guest
	if (!guest->init(cfg)) {
		delete guest;
		delete pfm;
		delete hv;

		ERROR << "Unable to initialise guest VM";
		return 1;
	}

	if (!guest->load(*kernel)) {
		delete guest;
		delete pfm;
		delete hv;

		ERROR << "Unable to load guest kernel";
		return 1;
	}

	guest->finalise_platform();
	guest->guest_entrypoint(kernel->entrypoint());
	guest->guest_stackpointer(pfm->stackpointer());

	if (cfg.cache_simulation) {
		auto sim = new simulation::cache::CacheSimulation();
		guest->add_simulation(*sim);
	}

	if (cfg.insn_count) {
		auto sim = new simulation::InstructionCounter();
		guest->add_simulation(*sim);
	}

	// Load the device-tree
	if (kernel->requires_device_tree()) {
		if (!cfg.device_tree) {
			delete guest;
			delete pfm;
			delete hv;

			ERROR << "You must specify a device-tree";
			return 1;
		} else {
			DeviceTreeLoader device_tree(cfg.device_tree.value(), 0x80010000);
			if (!guest->load(device_tree)) {
				delete guest;
				delete pfm;
				delete hv;

				ERROR << "Unable to load device tree";
				return 1;
			}
		}
	}

	// Initialise semihosting
	guest->init_semihosting();

	// Start the timer manager
	timer_manager.start();

	// Start the platform.
	pfm->start();

	fprintf(stderr, "*** guest starting\n");
	if (!guest->run()) {
		ERROR << "Unable to run CPU";
	}
	fprintf(stderr, "*** guest stopped\n");

	// Stop the platform
	pfm->stop();

	// Close the block device file
	// XXX: TODO: FIXME
	//bdev->close_file();

	// Stop the tick source
	timer_manager.stop();

	// Clean-up
	delete guest;
	delete pfm;
	delete hv;

	DEBUG << CONTEXT(Main) << "Complete";

	return 0;
}
