/* SPDX-License-Identifier: MIT */

#include <devices/io/console-uart.h>

#include <unistd.h>

using namespace captive::devices::io;

ConsoleUART::ConsoleUART() : FDUART(STDIN_FILENO, STDOUT_FILENO)
{
	
}

ConsoleUART::~ConsoleUART()
{

}

bool ConsoleUART::open()
{
	struct termios settings;
	tcgetattr(fileno(stdout), &settings);
	orig_settings = settings;
	
	cfmakeraw(&settings);
	settings.c_cc[VTIME] = 0;
	settings.c_cc[VMIN] = 1;

	tcsetattr(0, TCSANOW, &settings);
	
	return true;
}

bool ConsoleUART::close()
{
	tcsetattr(0, TCSANOW, &orig_settings);
	return true;
}
