/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <mutex>
#include <hypervisor/guest.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace virtio {

				struct VirtRingDescr {
					uint64_t addr;
					uint32_t length;

#define VRING_DESC_F_NEXT  1
#define VRING_DESC_F_WRITE  2
#define VRING_DESC_F_INDIRECT 4

					uint16_t flags;
					uint16_t next;

					inline bool has_next() const
					{
						return !!(flags & VRING_DESC_F_NEXT);
					}

					inline bool is_write() const
					{
						return !!(flags & VRING_DESC_F_WRITE);
					}

					inline bool is_indirect() const
					{
						return !!(flags & VRING_DESC_F_INDIRECT);
					}
				} __packed;

				struct VirtRingAvail {
#define VRING_AVAIL_F_NO_INTERRUPT 1

					uint16_t flags;
					uint16_t index;
					uint16_t ring[];
				} __packed;

				struct VirtRingUsedElem {
					uint32_t id;
					uint32_t len;
				} __packed;

				struct VirtRingUsed {
					uint16_t flags;
					uint16_t idx;
					VirtRingUsedElem ring[];
				} __packed;

				class VirtIO;

				class VirtQueue {
				public:

					VirtQueue(VirtIO& owner, int index) :
					_owner(owner),
					_index(index),
					_ready(false),
					_queue_num(0),
					_descriptor_gpa(0),
					_avail_gpa(0),
					_used_gpa(0),
					_descriptor_hva(nullptr),
					_avail_hva(nullptr),
					_used_hva(nullptr)
					{
					}

					inline int index() const
					{
						return _index;
					}

					inline bool ready() const
					{
						return _ready;
					}

					inline void ready(bool ready)
					{
						_ready = ready;
						if (ready) update_host_addresses();
					}

					inline uint64_t descriptor_gpa() const
					{
						return _descriptor_gpa;
					}

					inline uint64_t avail_gpa() const
					{
						return _avail_gpa;
					}

					inline uint64_t used_gpa() const
					{
						return _used_gpa;
					}

					void descriptor_gpa_low(uint32_t low)
					{
						_descriptor_gpa = (_descriptor_gpa & ~0xffffffffull) | low;
					}

					void descriptor_gpa_high(uint32_t high)
					{
						_descriptor_gpa = (_descriptor_gpa & 0xffffffffull) | (uint64_t) high << 32;
					}

					void avail_gpa_low(uint32_t low)
					{
						_avail_gpa = (_avail_gpa & ~0xffffffffull) | low;
					}

					void avail_gpa_high(uint32_t high)
					{
						_avail_gpa = (_avail_gpa & 0xffffffffull) | (uint64_t) high << 32;
					}

					void used_gpa_low(uint32_t low)
					{
						_used_gpa = (_used_gpa & ~0xffffffffull) | low;
						update_host_addresses();
					}

					void used_gpa_high(uint32_t high)
					{
						_used_gpa = (_used_gpa & 0xffffffffull) | (uint64_t) high << 32;
					}

					inline uint32_t num_max() const
					{
						return 0x1000;
					}

					inline uint32_t num() const
					{
						return _queue_num;
					}

					inline void num(uint32_t num)
					{
						_queue_num = num;
					}

					inline VirtRingDescr *pop(uint32_t& idx)
					{
						uint16_t num_heads = _avail_descrs->index - prev_idx;
						assert(num_heads <= _queue_num);

						if (num_heads == 0) {
							return NULL;
						}

						uint16_t head = _avail_descrs->ring[prev_idx++ % _queue_num];
						assert(head < _queue_num);

						idx = head;
						return get_descr(head);
					}

					inline void push(uint32_t elem_idx, uint32_t size)
					{
						assert(elem_idx < _queue_num);

						uint16_t idx = _used_descrs->idx % _queue_num;

						_used_descrs->ring[idx].id = elem_idx;
						_used_descrs->ring[idx].len = size;

						assert(_used_descrs->flags == 0);

						asm volatile("sfence" :: : "memory");
						__sync_fetch_and_add(&_used_descrs->idx, 1);
						//_used_descrs->idx++;
					}

					inline VirtRingDescr *get_descr(uint32_t idx)
					{
						assert(idx < _queue_num);

						if (!_vring_descrs) return NULL;

						return &_vring_descrs[idx];
					};

					inline VirtIO& owner() const
					{
						return _owner;
					}

					std::mutex lock;

				private:
					VirtIO& _owner;
					int _index;
					bool _ready;
					uint32_t _queue_num;

					uint64_t _descriptor_gpa, _avail_gpa, _used_gpa;
					void *_descriptor_hva, *_avail_hva, *_used_hva;

					VirtRingDescr *_vring_descrs;
					VirtRingAvail *_avail_descrs;
					VirtRingUsed *_used_descrs;
					uint16_t prev_idx;

					void init_vring()
					{
						_vring_descrs = (VirtRingDescr *) _descriptor_hva;
						_avail_descrs = (VirtRingAvail *) _avail_hva;
						_used_descrs = (VirtRingUsed *) _used_hva;

						prev_idx = 0;
					}

					void update_host_addresses()
					{
						if (!_owner.guest().resolve_gpa(_descriptor_gpa, _descriptor_hva)) {
							assert(false);
						}

						if (!_owner.guest().resolve_gpa(_avail_gpa, _avail_hva)) {
							assert(false);
						}

						if (!_owner.guest().resolve_gpa(_used_gpa, _used_hva)) {
							assert(false);
						}

						init_vring();
					}
				};
			}
		}
	}
}
