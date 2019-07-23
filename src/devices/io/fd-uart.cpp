/* SPDX-License-Identifier: MIT */

#include <devices/io/fd-uart.h>
#include <unistd.h>

using namespace captive::devices::io;

FDUART::FDUART(int infd, int outfd) : infd(infd), outfd(outfd)
{
	
}

FDUART::~FDUART()
{

}

bool FDUART::open()
{
	return true;
}

bool FDUART::close()
{
	return true;
}

bool FDUART::read_char(uint8_t& ch)
{
	return read(infd, (void *)&ch, 1) == 1;
}

bool FDUART::write_char(uint8_t ch)
{
	return write(outfd, &ch, 1) == 1;
}
