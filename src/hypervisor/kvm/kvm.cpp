/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <hypervisor/config.h>
#include <hypervisor/kvm/kvm.h>
#include <hypervisor/kvm/guest.h>
#include <platform/platform.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/kvm.h>

USE_CONTEXT(Hypervisor);

#define KVM_DEVICE_LOCATION		"/dev/kvm"

using namespace captive::engine;
using namespace captive::hypervisor;
using namespace captive::hypervisor::kvm;

KVM::KVM(Debugger *debugger) : Hypervisor(debugger), _initialised(false), kvm_fd(-1)
{
}

KVM::~KVM()
{
	DEBUG << CONTEXT(Hypervisor) << "Closing KVM device";
	close(kvm_fd);
	kvm_fd = -1;
}

bool KVM::init()
{
	// Ensure we're not already initialised.
	if (initialised()) {
		ERROR << CONTEXT(Hypervisor) << "KVM Hypervisor already initialised";
		return false;
	}

	// Initialise the underlying hypervisor.
	if (!Hypervisor::init())
		return false;

	// Attempt to open the KVM device node.
	DEBUG << CONTEXT(Hypervisor) << "Opening KVM device";
	kvm_fd = open(KVM_DEVICE_LOCATION, O_RDWR | O_CLOEXEC);
	if (kvm_fd < 0) {
		ERROR << "Unable to open KVM device";
		return false;
	}

	_initialised = true;

	DEBUG << CONTEXT(Hypervisor) << "KVM Version: " << version();

#ifdef KVM_CAP_READONLY_MEM
	DEBUG << "KVM read-only mem: " << check_extension(KVM_CAP_READONLY_MEM);
#endif
	
	return true;
}

Guest* KVM::create_guest(engine::Engine& engine, platform::Platform& pfm)
{
	// Ensure we've been initialised.
	if (!initialised()) {
		ERROR << CONTEXT(Hypervisor) << "KVM Hypervisor not yet initialised";
		return NULL;
	}

	// Validate the incoming guest configuration.
	if (!validate_configuration(pfm.config())) {
		ERROR << CONTEXT(Hypervisor) << "Invalid configuration";
		return NULL;
	}

	// Issue the ioctl to create a new VM.
	DEBUG << CONTEXT(Hypervisor) << "Creating new KVM VM";
	int guest_fd = ioctl(kvm_fd, KVM_CREATE_VM, 0);
	if (guest_fd < 0) {
		ERROR << CONTEXT(Hypervisor) << "Failed to create KVM VM";
		return NULL;
	}

	// Create (and register) the representative guest object.
	DEBUG << CONTEXT(Hypervisor) << "Creating guest object";
	KVMGuest *guest = new KVMGuest(*this, engine, pfm, guest_fd);
	known_guests.push_back(guest);

	return guest;
}

int KVM::check_extension(int extension) const
{
	return ioctl(kvm_fd, KVM_CHECK_EXTENSION, extension);
}

bool KVM::validate_configuration(const GuestConfiguration& config) const
{
	// Perform general configuration validation
	if (!config.validate()) {
		return false;
	}

	// TODO: KVM specific configuration validation
	return true;
}

int KVM::version() const
{
	if (!initialised()) {
		ERROR << CONTEXT(Hypervisor) << "KVM Hypervisor not yet initialised";
		return -1;
	}

	int rc = ioctl(kvm_fd, KVM_GET_API_VERSION, 0);
	if (rc == -1) {
		ERROR << CONTEXT(Hypervisor) << "Unable to ascertain KVM version: " << LAST_ERROR_TEXT;
		return -1;
	}

	return rc;
}

bool KVM::supported()
{
	DEBUG << CONTEXT(Hypervisor) << "Attempting to access KVM device";
	if (access(KVM_DEVICE_LOCATION, F_OK)) {
		return false;
	}

	return true;
}
