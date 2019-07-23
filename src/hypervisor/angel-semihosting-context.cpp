/* SPDX-License-Identifier: MIT */

#include <hypervisor/angel-semihosting-context.h>
#include <util/config/config.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

using namespace captive::hypervisor;

AngelSemihostingContext::AngelSemihostingContext(Guest& guest, const util::config::Configuration& cfg) : SemihostingContext(guest), _cfg(cfg)
{

}

bool AngelSemihostingContext::init()
{
	return true;
}

bool AngelSemihostingContext::handle_semihosting_call(SemihostingCallData& data)
{
	struct _argblock {
		unsigned long w0, w1, w2, w3;
	} *arg_block = (struct _argblock *)resolve_guest_ptr(data.arguments[0]);
	
	if (!arg_block) {
		fprintf(stderr, "semihosting: error: unable to resolve argument block from gpa=%lx\n", data.arguments[0]);
		return false;
	}
	
	switch (data.call_nr) {
	case 0x01:	// SYS_OPEN
		data.result = open((const char *)resolve_guest_ptr(arg_block->w0), O_RDONLY);
		break;
		
	case 0x02:	// SYS_CLOSE
		data.result = close(arg_block->w0);
		break;
		
	case 0x03:	// SYS_WRITEC
		fprintf(stdout, "%c", *(char *)arg_block);
		data.result = 0;
		break;

	case 0x04:	// SYS_WRITE0
		fprintf(stdout, "%s", (char *)arg_block);
		data.result = 0;
		break;

	case 0x05:	// SYS_WRITE
		data.result = write(arg_block->w0, (const void *)resolve_guest_ptr(arg_block->w1), (size_t)arg_block->w2);
		break;
		
	case 0x06:	// SYS_READ
	{
		data.result = read(arg_block->w0, (void *)resolve_guest_ptr(arg_block->w1), (size_t)arg_block->w2);
		break;
	}
		
	case 0x0c:	// SYS_FLEN
	{
		struct stat st;
		if (fstat(arg_block->w0, &st)) {
			data.result = -1;
		} else {
			data.result = st.st_size;
		}
		
		break;
	}
		
	case 0x15:	// SYS_GET_CMDLINE
		if (arg_block->w1 < 1) {
			data.result = -1;
		} else {
			std::string cc = _cfg.guest_kernel;
			
			for (const auto& arg : _cfg.cmdline) {
				cc += " " + arg;
			}
			
			strncpy((char *)resolve_guest_ptr(arg_block->w0), cc.c_str(), arg_block->w1 - 1);
			data.result = 0;
		}
		break;
		
	case 0x16:	// SYS_HEAPINFO
	{
		struct _heapinfo {
			int heap_base, heap_limit, stack_base, stack_limit;
		} *heapinfo = (_heapinfo *)resolve_guest_ptr(arg_block->w0);
		
		heapinfo->heap_base = 0;
		
		data.result = 0;
		break;
	}
	
	case 0x18:	// angel_SWIreason_ReportException
	{
		switch (data.arguments[0]) {
		case 0x20026:
			return false;
			
		default:
			data.result = -1;
			break;
		}
		
		break;
	}
		
	default:
		fprintf(stderr, "semihosting: error: unhandled semihosting call: nr=%lx, args=%lx\n", data.call_nr, data.arguments[0]);
		return false;
	}
	
	return true;
}
