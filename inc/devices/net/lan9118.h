/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/net/network-device.h>
#include <devices/net/fifo.h>
#include <devices/irq/irq-line.h>

namespace captive {
	namespace devices {
		namespace net {

			class LAN9118 : public NetworkDevice {
			public:
				LAN9118(irq::IRQLineBase& irq);
				virtual ~LAN9118();

				uint32_t size() const override
				{
					return 0x1000;
				}

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				std::string name() const
				{
					return "lan9118";
				}

				bool receive_packet(const uint8_t *buffer, uint32_t length) override;

			private:
				irq::IRQLineBase& irq;

				uint32_t pmt_ctrl, irq_cfg, irq_status, irq_en, fifo_int;
				uint32_t rx_cfg, tx_cfg, hw_cfg, gpio_cfg, gpt_cfg, word_swap, afc_cfg;

				struct {
					uint32_t cmd, data;
					uint8_t rom[128];
				} eeprom;

				struct {
					uint32_t status;
					uint32_t control;
					uint32_t advertise;
					uint32_t mode;
					uint32_t special;
					uint32_t irq_mask;
					uint32_t irq;
				} phy;

				uint32_t phy_read(uint8_t reg);
				void phy_write(uint8_t reg, uint32_t data);
				void phy_reset();
				void phy_update();
				void phy_update_irq();

				struct {
					uint32_t cmd;
					uint32_t data;

					uint32_t cr;
					uint32_t hashh, hashl;
					uint32_t mii_acc, mii_data;
					uint32_t flow;

					uint8_t addr[6];
				} mac;

				uint32_t mac_read(uint8_t reg);
				void mac_write(uint8_t reg, uint32_t data);

				void reset();

				struct {
					FIFO<uint32_t> tx_status;
					FIFO<uint32_t> rx_status;
					FIFO<uint32_t> tx_data;
					FIFO<uint32_t> rx_data;
				} fifos;

				void reconfigure_fifos();
				void update();

				struct {
					uint8_t state;
					uint32_t cmd_a, cmd_b;
					uint32_t buffer_size, offset, pad, len;
					uint8_t data[1024];
				} txp;

				void handle_tx_data_push(uint32_t data);
				void tx_packet(const uint8_t *buffer, uint32_t length);
				void rx_packet(const uint8_t *buffer, uint32_t length);
			};
		}
	}
}
