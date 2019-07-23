/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <hypervisor/gpa-resolver.h>

namespace captive {
	namespace devices {
		namespace io {
			class Keyboard;
			class Mouse;
		}

		namespace gfx {

			class VirtualScreenConfiguration {
			public:

				enum VirtualScreenMode {
					VS_None,
					VS_8bpp,
					VS_16bpp,
					VS_32bpp,
					VS_Doom,
				};

				explicit VirtualScreenConfiguration(uint32_t width, uint32_t height, VirtualScreenMode mode) : _width(width), _height(height), _mode(mode)
				{
				}

				inline uint32_t width() const
				{
					return _width;
				}

				inline uint32_t height() const
				{
					return _height;
				}

				inline VirtualScreenMode mode() const
				{
					return _mode;
				}

			private:
				uint32_t _width, _height;
				VirtualScreenMode _mode;
			};

			class VirtualScreen {
			public:
				VirtualScreen();
				virtual ~VirtualScreen();

				virtual bool initialise() = 0;

				bool reset();
				bool configure(const VirtualScreenConfiguration& config);

				void framebuffer(uint8_t *fb)
				{
					_framebuffer = fb;
				}

				void palette(uint8_t *pp)
				{
					_palette = pp;
				}

				inline void keyboard(io::Keyboard& kbd)
				{
					_kbd = &kbd;
				}

				inline io::Keyboard& keyboard() const
				{
					return *_kbd;
				}

				inline void mouse(io::Mouse& mse)
				{
					_mse = &mse;
				}

				inline io::Mouse& mouse() const
				{
					return *_mse;
				}

				inline uint8_t *framebuffer() const
				{
					return _framebuffer;
				}

				inline uint8_t *palette() const
				{
					return _palette;
				}

				inline bool configured() const
				{
					return _configured;
				}

			protected:
				virtual bool activate_configuration(const VirtualScreenConfiguration& cfg) = 0;
				virtual bool reset_configuration() = 0;

				inline const VirtualScreenConfiguration& config()
				{
					return _config;
				}

			private:
				VirtualScreenConfiguration _config;

				bool _configured;
				uint8_t *_framebuffer, *_palette;

				io::Keyboard *_kbd;
				io::Mouse *_mse;
			};
		}
	}
}
