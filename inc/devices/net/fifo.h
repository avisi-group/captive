/* SPDX-License-Identifier: MIT */
#pragma once

#include <malloc.h>

namespace captive {
	namespace devices {
		namespace net {

			template<typename elem_t>
			struct FIFO {
			public:

				FIFO() : head(0), used(0), size(0), data(NULL)
				{
				}

				~FIFO()
				{
					if (data) ::free(data);
				}

				void configure(uint32_t nr_elems)
				{
					reset();

					size = nr_elems;
					data = (elem_t *) realloc(data, sizeof(elem_t) * nr_elems);
				}

				void push(elem_t e)
				{
					assert(data);

					uint32_t pos = head + used;
					if (pos >= size) {
						pos -= size;
					}

					data[pos] = e;
					used++;
				}

				elem_t peek() const
				{
					assert(data);

					return data[head];
				}

				elem_t pop()
				{
					assert(data);

					elem_t e = data[head];
					if (used != 0) {
						used--;
						head++;

						if (head >= size) {
							head -= size;
						}
					}

					return e;
				}

				bool full() const
				{
					assert(data);
					return used == size;
				}

				void reset()
				{
					head = used = 0;
				}

				constexpr uint32_t fifo_size() const
				{
					return size;
				}

				uint32_t count() const
				{
					return used;
				}

				uint32_t free() const
				{
					return size - used;
				}

			private:
				uint32_t head, used, size;
				elem_t *data;
			};
		}
	}
}
