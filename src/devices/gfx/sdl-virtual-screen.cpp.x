#include <devices/gfx/sdl-virtual-screen.h>
#include <devices/io/keyboard.h>
#include <devices/io/mouse.h>
#include <hypervisor/kvm/cpu.h>
#include <captive.h>

#include <unistd.h>
#include <thread>
#include <pthread.h>

USE_CONTEXT(VirtualScreen);
DECLARE_CHILD_CONTEXT(SDLVirtualScreen, VirtualScreen);

using namespace captive::devices::gfx;

static const uint32_t sdl_scancode_map[] = {
	0, 0, 0, 0,

	// A - M
	0x1c, 0x32, 0x21, 0x23, 0x24, 0x2b, 0x34, 0x33, 0x43, 0x3b, 0x42, 0x4b, 0x3a,
	// N - Z
	0x31, 0x44, 0x4d, 0x15, 0x2d, 0x1b, 0x2c, 0x3c, 0x2a, 0x1d, 0x22, 0x35, 0x1a,
	// 0 - 9
	0x16, 0x1e, 0x26, 0x25, 0x2e, 0x36, 0x3d, 0x3e, 0x46, 0x45,

	0x5a, 0x76, 0x66, 0x0d, 0x29,
	0x4e, 0x55, 0x54, 0x5b, 0x5d, 0x5d, 0x4c, 0x52, 0x0e, 0x41, 0x49, 0x4a,

	// CAPSLOCK
	0x58,

	// F1 - F12
	0x05, 0x06, 0x04, 0x0c, 0x03, 0x0b, 0x83, 0x0a, 0x01, 0x09, 0x78, 0x07,

	// PRNT SCR, SCRL LCK, PAUSE
	0,           0,        0,

	// INS  HOME    PGUP    DEL     END     PGDN    RT      LT      DN      UP
	0xe070, 0xe06c, 0xe07d, 0xe071, 0xe069, 0xe07a, 0xe074, 0xe06b, 0xe072, 0xe075,

	// NUMLOCK
	0x77,

	// DIV  MUL  MINUS  PLUS  ENTER
	0xe04a, 0x7c, 0x7b, 0x79, 0xe05a,

	// KP 1 - 9, 0
	0x69, 0x72, 0x7a, 0x6b, 0x73, 0x74, 0x6c, 0x75, 0x7d, 0x70,

	// KP .
	0x71,

	// BACKSLASH
	0x5d,				// 100

	// APPS
	0xe02f,
	0, // POWER
	0, // KP EQ
	// Extra F keys
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	// Utility Keys
/*116*/	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/*130*/	0, 0, 0,

/*133*/	0, // KP COMMA
		0, // SOME WEIRD EQUALS
		// INTERNATIONAL KEYS
/*135*/	0, 0, 0, 0, 0, 0, 0, 0, 0,
		// LANGUAGE KEYS
/*144*/	0, 0, 0, 0, 0, 0, 0, 0, 0,

		// OTHER
/*153*/	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/*165*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/*176*/	0, 0, 0, 0, 0, 0,
/*182*/	0, 0, 0, 0, 0, 0,
/*188*/	0, 0, 0, 0, 0, 0,
/*194*/	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

		0, 0,

		// LCTRL LSHIFT LALT  LGUI    RCTRL   RSHIFT RALT    RGUI
		0x14,    0x12,  0x11, 0xe01f, 0xe014, 0x59,  0xe011, 0xe027
};

std::mutex SDLVirtualScreen::_sdl_lock;
bool SDLVirtualScreen::_sdl_initialised = false;

SDLVirtualScreen::SDLVirtualScreen() : _cpu(NULL), hw_accelerated(false), terminate(false), _sdl_mode(0), window_thread(NULL)
{

}

SDLVirtualScreen::~SDLVirtualScreen()
{
	if (window_thread) {
		terminate = true;
		window_thread->join();
		window_thread = NULL;
	}
}

void SDLVirtualScreen::window_thread_proc_tramp(SDLVirtualScreen *o)
{
	pthread_setname_np(pthread_self(), "virt-screen");
	o->window_thread_proc();
}

void SDLVirtualScreen::check_grab()
{
	if (!SDL_GetWindowGrab(window)) {
		SDL_SetWindowGrab(window, SDL_TRUE);
		SDL_SetWindowTitle(window, "LCD (press right-control to release)");
		SDL_ShowCursor(0);
	}
}

void SDLVirtualScreen::release_grab()
{
	SDL_SetWindowGrab(window, SDL_FALSE);
	SDL_SetWindowTitle(window, "LCD");
	SDL_ShowCursor(1);
}

void SDLVirtualScreen::window_thread_proc()
{
	DEBUG << CONTEXT(SDLVirtualScreen) << "Welp.  Here we go!";

	while (!terminate) {
		// Stop the event queue from overflowing

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type)	{
			case SDL_KEYDOWN:
				check_grab();
				
				if (e.key.keysym.scancode == SDL_SCANCODE_RCTRL) {
					// Only release grab on KEY-UP
				} else {
					keyboard().key_down(sdl_scancode_map[e.key.keysym.scancode]);
				}
				
				break;

			case SDL_KEYUP:
				check_grab();
				
				if (e.key.keysym.scancode == SDL_SCANCODE_RCTRL) {
					release_grab();
				} else {
					keyboard().key_up(sdl_scancode_map[e.key.keysym.scancode]);
				}

				break;

			case SDL_MOUSEBUTTONDOWN:
				check_grab();
				
				switch (e.button.button) {
				case 1: mouse().button_down(0); break;
				case 2: mouse().button_down(2); break;
				case 3: mouse().button_down(1); break;
				}
				
				break;

			case SDL_MOUSEBUTTONUP:
				check_grab();
				
				switch (e.button.button) {
				case 1: mouse().button_up(0); break;
				case 2: mouse().button_up(2); break;
				case 3: mouse().button_up(1); break;
				}
				break;

			case SDL_MOUSEMOTION:
				mouse().mouse_move(e.motion.x, -e.motion.y);
				break;

			case SDL_QUIT:
				terminate = true;

				if (_cpu) {
					_cpu->stop();
				}

				break;
			}
		}

		// Draw a frame
		draw_frame();
		usleep(20000);
	}
}

bool SDLVirtualScreen::initialise()
{
	if (window_thread) {
		std::unique_lock<std::mutex> lock(texture_lock);
		
		SDL_DestroyTexture(window_texture);
		window_texture = SDL_CreateTexture(renderer, _sdl_mode, SDL_TEXTUREACCESS_STREAMING, config().width(), config().height());
		if(!window_texture) {
			assert(false);
		}
		
		return true;
	}
	
	_sdl_lock.lock();
	if (!_sdl_initialised) {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		_sdl_initialised = true;
	}
	_sdl_lock.unlock();

	window = SDL_CreateWindow("LCD", 0, 0, config().width(), config().height(), SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (!window) {
		ERROR << CONTEXT(SDLVirtualScreen) << "Could not create SDL window!";
		return false;
	}

	// First, try and start a HW accelerated renderer
	if (hw_accelerated) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	} else {
		renderer = NULL;
	}

	// If we fail to start with HW acceleration, try and get a SW renderer
	if (!renderer) {
		hw_accelerated = false;

		WARNING << CONTEXT(SDLVirtualScreen) << "Could  not create HW Accelerated SDL renderer. Falling back to software.";
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

		if (!renderer) {
			ERROR << CONTEXT(SDLVirtualScreen) << "Attempted but failed to fall back to software renderer.";
			return false;
		}
	}

	window_texture = SDL_CreateTexture(renderer, _sdl_mode, SDL_TEXTUREACCESS_STREAMING, config().width(), config().height());
	if(!window_texture) {
		ERROR << CONTEXT(SDLVirtualScreen) << "Could not create window texture! Terminating.";
		return false;
	}

	terminate = false;
	window_thread = new std::thread(window_thread_proc_tramp, this);

	return true;
}

bool SDLVirtualScreen::activate_configuration(const VirtualScreenConfiguration& cfg)
{
	_sdl_mode = SDL_PIXELFORMAT_ABGR1555;
	switch(cfg.mode()) {
	case VirtualScreenConfiguration::VS_16bpp:
		_sdl_mode = SDL_PIXELFORMAT_RGB565;
		frame_drawer = &SDLVirtualScreen::draw_rgb;
		pitch = cfg.width() * 2;
		break;

	case VirtualScreenConfiguration::VS_8bpp:
		_sdl_mode = SDL_PIXELFORMAT_RGBA8888;
		frame_drawer = &SDLVirtualScreen::draw_palette;
		pitch = cfg.width() * 4;
		break;

	case VirtualScreenConfiguration::VS_Doom:
		_sdl_mode = SDL_PIXELFORMAT_RGB888;
		frame_drawer = &SDLVirtualScreen::draw_doom;
		break;

	default:
		ERROR << CONTEXT(SDLVirtualScreen) << "Unsupported screen mode " << cfg.mode();
		return false;
	}

	return true;
}

bool SDLVirtualScreen::reset_configuration()
{
	return true;
}

void SDLVirtualScreen::draw_frame()
{
	std::unique_lock<std::mutex> lock(texture_lock);
	
	SDL_RenderClear(renderer);

	(this->*frame_drawer)();

	SDL_RenderCopy(renderer, window_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void SDLVirtualScreen::draw_doom()
{

}

void SDLVirtualScreen::draw_palette()
{
	uint8_t fb[config().width() * config().height() * 4];
	
	for (unsigned int pidx = 0; pidx < config().width() * config().height(); pidx++) {
		uint32_t pv = ((uint16_t *)palette())[framebuffer()[pidx]];
		fb[(pidx * 4) + 3] = (pv & 0x1f) << 3;
		fb[(pidx * 4) + 2] = ((pv >> 5) & 0x1f) << 3;
		fb[(pidx * 4) + 1] = ((pv >> 10) & 0x1f) << 3;
		fb[(pidx * 4) + 0] = 0xff;
	}
	
	SDL_UpdateTexture(window_texture, NULL, (void *)fb, pitch);
}

void SDLVirtualScreen::draw_rgb()
{
	SDL_UpdateTexture(window_texture, NULL, (void *)framebuffer(), pitch);
}
