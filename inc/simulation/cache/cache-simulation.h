/* SPDX-License-Identifier: MIT */
#pragma once

#include <simulation/simulation.h>
#include <cmath>

namespace captive {
	namespace simulation {
		namespace cache {

			template<uint32_t total_size, uint32_t line_size, uint8_t number_of_ways, bool vidx, bool vtag, bool nonseq>
			struct CPUCache {
			public:

				CPUCache() : rrp(0x9E3779B9), last_line(-1), read_hits(0), read_misses(0), write_hits(0), write_misses(0)
				{
				}

			private:
				static constexpr int number_of_lines = (int) (total_size / line_size);
				static constexpr int log2_number_of_lines = (int) std::log2(number_of_lines);

				static constexpr int number_of_sets = (int) (number_of_lines / number_of_ways);
				static constexpr int log2_number_of_sets = (int) std::log2(number_of_sets);

				static constexpr int log2_number_of_ways = (int) std::log2(number_of_ways);

				static constexpr int offset_bits = (int) std::log2(line_size);
				static constexpr int offset_mask = ((1 << offset_bits) - 1);

				static constexpr int set_bits = log2_number_of_sets;
				static constexpr int set_mask = ((1 << set_bits) - 1);

				static constexpr int tag_bits = 31 - (set_bits + offset_bits);
				static constexpr int tag_mask = ((1 << tag_bits) - 1);

				uint32_t tags[number_of_lines];
				uint32_t rrp;
				uint32_t last_line;

				inline constexpr uint32_t cache_line(uint32_t vaddr, uint32_t paddr) const __attribute__((pure))
				{
					return set_of(vaddr, paddr);
				}

				inline constexpr uint32_t tag_addr(uint32_t vaddr, uint32_t paddr) const __attribute__((pure))
				{
					return vtag ? vaddr : paddr;
				}

				inline constexpr uint32_t set_addr(uint32_t vaddr, uint32_t paddr) const __attribute__((pure))
				{
					return vidx ? vaddr : paddr;
				}

				inline constexpr uint32_t tag_of(uint32_t vaddr, uint32_t paddr) const __attribute__((pure))
				{
					//return (tag_addr(vaddr, paddr) >> (set_bits + offset_bits)) & tag_mask;
					return(tag_addr(vaddr, paddr) & (tag_mask << (set_bits + offset_bits)));
				}

				inline constexpr uint32_t set_of(uint32_t vaddr, uint32_t paddr) const __attribute__((pure))
				{
					return(set_addr(vaddr, paddr) >> offset_bits) & set_mask;
				}

				inline constexpr int tag_slot(uint32_t vaddr, uint32_t paddr, uint8_t way) const __attribute__((pure))
				{
					//return tags[index_of(vaddr, paddr) + number_of_lines::value * way];
					return(set_of(vaddr, paddr) << log2_number_of_ways) +way;
				}

				inline bool tag_match(uint32_t vaddr, uint32_t paddr, uint8_t way) const
				{
					return tags[tag_slot(vaddr, paddr, way)] == tag_of(vaddr, paddr);
				}

				inline void update_tag(uint32_t vaddr, uint32_t paddr, uint8_t way)
				{
					tags[tag_slot(vaddr, paddr, way)] = tag_of(vaddr, paddr);
				}

				inline bool hit(uint32_t vaddr, uint32_t paddr) const
				{
					if (number_of_ways == 2) {
						return tag_match(vaddr, paddr, 0) || tag_match(vaddr, paddr, 1);
					} else if (number_of_ways == 4) {
						return tag_match(vaddr, paddr, 0) ||
							tag_match(vaddr, paddr, 1) ||
							tag_match(vaddr, paddr, 2) ||
							tag_match(vaddr, paddr, 3);
					}
				}

				inline void replace(uint32_t vaddr, uint32_t paddr)
				{
					if (number_of_ways == 2) update_tag(vaddr, paddr, rrp & 1);
					else if (number_of_ways == 4) update_tag(vaddr, paddr, rrp & 2);

					rrp = ((rrp & 1) << 31) | (rrp >> 1);
				}

			public:
				uint64_t read_hits, read_misses, write_hits, write_misses;

				inline bool read(uint32_t vaddr, uint32_t paddr, uint8_t sz)
				{
					if (hit(vaddr, paddr)) {
						if (nonseq) {
							if (cache_line(vaddr, paddr) == last_line) return true;
							last_line = cache_line(vaddr, paddr);
						}

						read_hits++;
						return true;
					} else {
						read_misses++;
						replace(vaddr, paddr);
						return false;
					}
				}

				inline bool write(uint32_t vaddr, uint32_t paddr, uint8_t sz)
				{
					if (hit(vaddr, paddr)) {
						if (nonseq) {
							if (cache_line(vaddr, paddr) == last_line) return true;
							last_line = cache_line(vaddr, paddr);
						}

						write_hits++;
						return true;
					} else {
						write_misses++;
						replace(vaddr, paddr);
						return false;
					}
				}
			};

			class CacheSimulation : public Simulation {
			public:
				bool init() override;
				void start() override;
				void stop() override;

				void process_events(const EventPacket *events, uint32_t count) override;

				Events::Events required_events() const override
				{
					return(Events::Events)(Events::InstructionFetch | Events::MemoryRead | Events::MemoryWrite);
				}

				void dump() override;

				void begin_record() override;
				void end_record() override;

			private:
				simulation::cache::CPUCache<32768, 32, 2, true, false, false> l1i;
				simulation::cache::CPUCache<32768, 64, 4, true, true, false> l1d;

				uint64_t l1d_read_hits, l1d_read_misses, l1d_write_hits, l1d_write_misses;
				uint64_t l1i_fetch_hits, l1i_fetch_misses;
			};
		}
	}
}
