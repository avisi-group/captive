/* SPDX-License-Identifier: MIT */

#include <simulation/cache/cache-simulation.h>

using namespace captive::simulation::cache;

bool CacheSimulation::init()
{
	return true;
}

void CacheSimulation::start()
{
}

void CacheSimulation::stop()
{
}

void CacheSimulation::dump()
{
	fprintf(stderr, "*** ABSOLUTE CACHE STATISTICS ***\n\r");
	fprintf(stderr, "l1i: fetch: accesses=%lu, hits=%lu, misses=%lu\n\r", l1i.read_misses + l1i.read_hits, l1i.read_hits, l1i.read_misses);
	fprintf(stderr, "l1d:  comb: accesses=%lu, hits=%lu, misses=%lu\n\r", l1d.write_misses + l1d.write_hits + l1d.read_misses + l1d.read_hits, l1d.write_hits + l1d.read_hits, l1d.write_misses + l1d.read_misses);
	fprintf(stderr, "l1d:  read: accesses=%lu, hits=%lu, misses=%lu\n\r", l1d.read_misses + l1d.read_hits, l1d.read_hits, l1d.read_misses);
	fprintf(stderr, "l1d: write: accesses=%lu, hits=%lu, misses=%lu\n\r", l1d.write_misses + l1d.write_hits, l1d.write_hits, l1d.write_misses);
	
//	fprintf(stderr, "l2:   read: accesses=%lu, hits=%lu, misses=%lu\n", l2.read_misses + l2.read_hits, l2.read_hits, l2.read_misses);
//	fprintf(stderr, "l2:  write: accesses=%lu, hits=%lu, misses=%lu\n", l2.write_misses + l2.write_hits, l2.write_hits, l2.write_misses);
}


void CacheSimulation::process_events(const EventPacket *events, uint32_t count)
{
	for (uint32_t i = 0; i < count; i++) {
		uint32_t virt_addr = events[i].address;
		uint32_t phys_addr = (events[i].phys_page << 12) | (events[i].address & 0xfff);
		
		if (events[i].type == EventPacket::MEMORY_READ) {
			l1d.read(virt_addr, phys_addr, events[i].size);
		} else if (events[i].type == EventPacket::MEMORY_WRITE) {
			l1d.write(virt_addr, phys_addr, events[i].size);
		} else if (events[i].type == EventPacket::INSTRUCTION_FETCH) {
			l1i.read(virt_addr, phys_addr, events[i].size);
		}
	}
}

void CacheSimulation::begin_record()
{
	l1d_read_hits = l1d.read_hits;
	l1d_read_misses = l1d.read_misses;
	l1d_write_hits = l1d.write_hits;
	l1d_write_misses = l1d.write_misses;
	l1i_fetch_hits = l1i.read_hits;
	l1i_fetch_misses = l1i.read_misses;
}

void CacheSimulation::end_record()
{
	fprintf(stderr, "*** DELTA CACHE STATISTICS ***\n\r");
	fprintf(stderr, "l1i: fetch: accesses=%lu, hits=%lu, misses=%lu\n\r", 
			(l1i.read_misses + l1i.read_hits) - (l1i_fetch_misses + l1i_fetch_hits), 
			l1i.read_hits - l1i_fetch_hits,
			l1i.read_misses - l1i_fetch_misses);

	fprintf(stderr, "l1d:  read: accesses=%lu, hits=%lu, misses=%lu\n\r", 
			(l1d.read_misses + l1d.read_hits) - (l1d_read_misses + l1d_read_hits), 
			l1d.read_hits - l1d_read_hits, 
			l1d.read_misses - l1d_read_misses);
	
	fprintf(stderr, "l1d: write: accesses=%lu, hits=%lu, misses=%lu\n\r",
			(l1d.write_misses + l1d.write_hits) - (l1d_write_misses + l1d_write_hits), 
			l1d.write_hits - l1d_write_hits, 
			l1d.write_misses - l1d_write_misses);
}
