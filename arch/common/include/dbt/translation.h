/* SPDX-License-Identifier: MIT */

#pragma once

#include <printf.h>
#include <malloc/malloc.h>

extern "C" uint32_t block_trampoline(void *state, void *native_code);

namespace captive {
	namespace arch {
		namespace jit {

			class Translation {
			public:

				Translation(void *code_ptr, size_t size) : _code_ptr(code_ptr), _code_size(size)
				{
				}

				~Translation()
				{
					captive::arch::malloc::code_alloc.free(_code_ptr);
				}

				uint32_t invoke() const
				{
					return block_trampoline(nullptr, _code_ptr);
				}

				void *raw_code() const
				{
					return _code_ptr;
				}

				size_t size() const
				{
					return _code_size;
				}

				void set_direct_jump_target(uint64_t target)
				{
					*(uint64_t *) ((uintptr_t) _code_ptr + _code_size - 31) = target;
				}

				void set_predicated_direct_jump_target(uint64_t target)
				{
					*(uint64_t *) ((uintptr_t) _code_ptr + _code_size - 61) = target;
				}

				void set_predicated_direct_jump_fallthrough(uint64_t fallthrough)
				{
					*(uint64_t *) ((uintptr_t) _code_ptr + _code_size - 51) = fallthrough;
				}

			private:
				void *_code_ptr;
				size_t _code_size;
			};
		}
	}
}
