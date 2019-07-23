/* SPDX-License-Identifier: MIT */

#include <devices/io/null-uart.h>
#include <unistd.h>

using namespace captive::devices::io;

NullUART::NullUART()
{
	
}

NullUART::~NullUART() {

}

bool NullUART::open()
{
	return true;
}

bool NullUART::close()
{
	return true;
}

bool NullUART::read_char(uint8_t& ch)
{
	return false;
}

bool NullUART::write_char(uint8_t ch)
{
	return true;
}
