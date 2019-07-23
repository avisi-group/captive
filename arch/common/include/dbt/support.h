/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace terrible {

				struct arg_match_struct {
					void *ptr;
				};
			}
		}
	}
}

inline void *operator new(dbt_size_t, captive::arch::dbt::terrible::arg_match_struct *__p){return __p->ptr;}

namespace captive {
	namespace arch {
		namespace dbt {

			enum class AllocClass {
				DATA,
				TRANSLATED_CODE
			};

			class Support {
			public:
				// Object allocation helper

				template<class T, typename ... Args>
				T *alloc_obj(Args&& ... x)
				{
					// Allocate data storage for the object.
					terrible::arg_match_struct arg_match;
					arg_match.ptr = alloc(sizeof(T), AllocClass::DATA);

					// Invoke the constructor via a specialised form of placement new.
					return new (&arg_match)T(x...);
				}

				// Object release helper

				template<class T>
				void free_obj(T *ptr)
				{
					// Invoke the object's destructor.
					ptr->~T();

					// Release the data memory.
					free(ptr, AllocClass::DATA);
				}

				virtual void assertion_fail(const char *msg) = 0;
				virtual void debug_printf(const char *fmt, ...) = 0;

				virtual dbt_u64 ticks() const
				{
					return 0;
				}

				virtual void *alloc(dbt_size_t size, AllocClass cls) = 0;
				virtual void *realloc(void *ptr, dbt_size_t new_size, AllocClass cls) = 0;
				virtual void free(void *ptr, AllocClass cls) = 0;

				virtual void debug_dump_mem()
				{
				};

				virtual void memcpy(void *dest, const void *src, dbt_size_t size) = 0;
			};
		}
	}
}
