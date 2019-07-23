/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/gfx/virtual-screen.h>
#include <mutex>
#include <thread>

#include <SDL2/SDL.h>

namespace captive {
	namespace hypervisor {
		class CPU;
	}

	namespace devices {
		namespace gfx {

			class SDLVirtualScreen : public VirtualScreen {
			public:
				SDLVirtualScreen();
				virtual ~SDLVirtualScreen();

				bool initialise() override;

				inline void cpu(hypervisor::CPU& cpu)
				{
					_cpu = &cpu;
				}

			protected:
				bool activate_configuration(const VirtualScreenConfiguration& cfg) override;
				bool reset_configuration() override;

			private:
				static std::mutex _sdl_lock;
				static bool _sdl_initialised;

				void check_grab();
				void release_grab();

				static void window_thread_proc_tramp(SDLVirtualScreen *o);
				void window_thread_proc();
				void draw_frame();

				void draw_doom();
				void draw_palette();
				void draw_rgb();

				typedef void (SDLVirtualScreen::*frame_drawer_fn_t)(void);
				frame_drawer_fn_t frame_drawer;

				hypervisor::CPU *_cpu;

				bool hw_accelerated, terminate;

				int _sdl_mode;
				uint32_t pitch;

				SDL_Window *window;
				SDL_Renderer *renderer;
				SDL_Texture *window_texture;
				std::mutex texture_lock;

				std::thread *window_thread;
			};
		}
	}
}
