/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {

			struct x86_pte {

				union {
					uint64_t value;

					struct {
						uint64_t present : 1;
						uint64_t ignored : 63;
					} not_present;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t dirty : 1;
						uint64_t pat : 1;
						uint64_t global : 1;
						uint64_t ignored1 : 3;
						uint64_t base_address : 40;
						uint64_t ignored2 : 7;
						uint64_t prot_key : 4;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 12ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 12ull;
						}
					} page;
				};
			} packed;

			struct x86_pde {

				union {
					uint64_t value;

					struct {
						uint64_t present : 1;
						uint64_t reserved : 63;
					} not_present;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t ignored1 : 1;
						uint64_t size : 1;
						uint64_t ignored2 : 4;
						uint64_t base_address : 40;
						uint64_t ignored3 : 11;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 12ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 12ull;
						}
					} page_table;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t dirty : 1;
						uint64_t size : 1;
						uint64_t global : 1;
						uint64_t ignored1 : 3;
						uint64_t pat : 1;
						uint64_t reserved : 8;
						uint64_t base_address : 31;
						uint64_t ignored2 : 7;
						uint64_t prot_key : 4;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 21ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 21ull;
						}
					} page2mb;
				};
			} packed;

			struct x86_pdpte {

				union {
					uint64_t value;

					struct {
						uint64_t present : 1;
						uint64_t reserved : 63;
					} not_present;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t ignored1 : 1;
						uint64_t size : 1;
						uint64_t ignored2 : 4;
						uint64_t base_address : 40;
						uint64_t ignored3 : 11;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 12ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 12ull;
						}
					} page_directory;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t dirty : 1;
						uint64_t size : 1;
						uint64_t global : 1;
						uint64_t ignored1 : 3;
						uint64_t pat : 1;
						uint64_t reserved : 17;
						uint64_t base_address : 22;
						uint64_t ignored2 : 7;
						uint64_t prot_key : 4;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 30ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 30ull;
						}
					} page1gb;
				};
			} packed;

			struct x86_pml4e {

				union {
					uint64_t value;

					struct {
						uint64_t present : 1;
						uint64_t reserved : 63;
					} not_present;

					struct {
						uint64_t present : 1;
						uint64_t writable : 1;
						uint64_t user : 1;
						uint64_t write_through : 1;
						uint64_t cache_disable : 1;
						uint64_t accessed : 1;
						uint64_t ignored1 : 1;
						uint64_t reserved : 1;
						uint64_t ignored2 : 4;
						uint64_t base_address : 40;
						uint64_t ignored3 : 11;
						uint64_t execute_disable : 1;

						hpa_t actual_base_address() const
						{
							return(uint64_t) base_address << 12ull;
						}

						void actual_base_address(hpa_t pa)
						{
							base_address = pa >> 12ull;
						}
					} page_directory_ptr;
				};
			} packed;
		}
	}
}
