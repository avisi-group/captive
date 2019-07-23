/* SPDX-License-Identifier: MIT */

#include <devices/io/ps2.h>
#include <captive.h>
#include <unistd.h>

/* Keyboard Commands */
#define KBD_CMD_SET_LEDS	0xED	/* Set keyboard leds */
#define KBD_CMD_ECHO		0xEE
#define KBD_CMD_SCANCODE	0xF0	/* Get/set scancode set */
#define KBD_CMD_GET_ID		0xF2	/* get keyboard ID */
#define KBD_CMD_SET_RATE	0xF3	/* Set typematic rate */
#define KBD_CMD_ENABLE		0xF4	/* Enable scanning */
#define KBD_CMD_RESET_DISABLE	0xF5	/* reset and disable scanning */
#define KBD_CMD_RESET_ENABLE   	0xF6    /* reset and enable scanning */
#define KBD_CMD_RESET		0xFF	/* Reset */

/* Keyboard Replies */
#define KBD_REPLY_POR		0xAA	/* Power on reset */
#define KBD_REPLY_ID		0xAB	/* Keyboard ID */
#define KBD_REPLY_ACK		0xFA	/* Command ACK */
#define KBD_REPLY_RESEND	0xFE	/* Command NACK, send the cmd again */

/* Mouse Commands */
#define AUX_SET_SCALE11		0xE6	/* Set 1:1 scaling */
#define AUX_SET_SCALE21		0xE7	/* Set 2:1 scaling */
#define AUX_SET_RES			0xE8	/* Set resolution */
#define AUX_GET_STATUS		0xE9	/* Get status */
#define AUX_SET_STREAM		0xEA	/* Set stream mode */
#define AUX_POLL			0xEB	/* Poll */
#define AUX_RESET_WRAP		0xEC	/* Reset wrap mode */
#define AUX_SET_WRAP		0xEE	/* Set wrap mode */
#define AUX_SET_REMOTE		0xF0	/* Set remote mode */
#define AUX_GET_TYPE		0xF2	/* Get type */
#define AUX_SET_SAMPLE		0xF3	/* Set sample rate */
#define AUX_ENABLE_DEV		0xF4	/* Enable aux device */
#define AUX_DISABLE_DEV		0xF5	/* Disable aux device */
#define AUX_SET_DEFAULT		0xF6
#define AUX_RESET			0xFF	/* Reset aux device */
#define AUX_ACK				0xFA	/* Command byte ACK. */

using namespace captive::devices::io;

PS2Device::PS2Device(irq::IRQLineBase& irq) : _irq(irq), irq_enabled(false)
{

}

PS2KeyboardDevice::PS2KeyboardDevice(irq::IRQLineBase& irq) : PS2Device(irq), last_command(0)
{

}

PS2MouseDevice::PS2MouseDevice(irq::IRQLineBase& irq) : PS2Device(irq), last_command(0), status(0), resolution(0), sample_rate(0), last_x(0), last_y(0), button_state(0), wrapping_mode(false)
{

}

void PS2KeyboardDevice::send_command(uint32_t command)
{
	std::unique_lock<std::mutex> l(process_lock);

	switch (last_command) {
	case 0:
		switch (command) {
		case KBD_CMD_RESET:
			clear_queue();
			queue_data(KBD_REPLY_ACK);
			queue_data(KBD_REPLY_POR);
			break;

		case KBD_CMD_GET_ID:
			queue_data(KBD_REPLY_ACK);
			queue_data(KBD_REPLY_ID);
			queue_data(0x41);
			break;

		case KBD_CMD_SCANCODE:
		case KBD_CMD_SET_LEDS:
		case KBD_CMD_SET_RATE:
			last_command = command;
			queue_data(KBD_REPLY_ACK);
			break;

		default:
			queue_data(KBD_REPLY_ACK);
			break;
		}
		break;

	case KBD_CMD_SCANCODE:
		last_command = 0;
		if (command == 0) {
			// GET SCANCODE SET
			queue_data(0x41);
		} else {
			// SET SCANCODE SET
			queue_data(KBD_REPLY_ACK);
		}
		break;

	case KBD_CMD_SET_LEDS:
		last_command = 0;
		queue_data(KBD_REPLY_ACK);
		break;

	case KBD_CMD_SET_RATE:
		last_command = 0;
		queue_data(KBD_REPLY_ACK);
		break;

	default:
		last_command = 0;
		queue_data(KBD_REPLY_ACK);
		break;
	}

}

void PS2KeyboardDevice::key_down(uint32_t keycode)
{
	std::unique_lock<std::mutex> l(process_lock);

	if ((keycode & 0xff00) == 0xe000)
		queue_data(0xe0);
	queue_data(keycode & 0xff);
}

void PS2KeyboardDevice::key_up(uint32_t keycode)
{
	std::unique_lock<std::mutex> l(process_lock);

	if ((keycode & 0xff00) == 0xe000)
		queue_data(0xe0);
	queue_data(0xf0);
	queue_data(keycode & 0xff);
}

#define STATUS_SCALE21		(1 << 4)
#define STATUS_REPORTING	(1 << 5)
#define STATUS_REMOTE		(1 << 6)

void PS2MouseDevice::send_command(uint32_t command)
{
	std::unique_lock<std::mutex> l(process_lock);
	
	switch (last_command) {
	case 0:
	case AUX_RESET:
		switch (command) {
		case AUX_RESET:
			clear_queue();

			status = 0;
			resolution = 2;
			sample_rate = 100;

			queue_data(AUX_ACK);		// Acknowledge
			queue_data(0xaa);			// Self-test OK
			queue_data(0x00);			// Device ID
			break;

		case AUX_GET_TYPE:
			queue_data(AUX_ACK);
			queue_data(0x00);
			break;

		case AUX_SET_DEFAULT:
			status = 0;
			resolution = 2;
			sample_rate = 100;

			queue_data(AUX_ACK);
			break;

		case AUX_SET_SAMPLE:
		case AUX_SET_RES:
			last_command = command;
			queue_data(AUX_ACK);
			break;

		case AUX_SET_SCALE11:
			status &= ~STATUS_SCALE21;
			queue_data(AUX_ACK);
			break;
			
		case AUX_SET_SCALE21:
			status |= STATUS_SCALE21;
			queue_data(AUX_ACK);
			break;

		case AUX_GET_STATUS:
			queue_data(AUX_ACK);
			queue_data(status);
			queue_data(resolution);
			queue_data(sample_rate);
			break;

		case AUX_SET_WRAP:
			throw 0;
			
		case AUX_SET_STREAM:
			status &= ~STATUS_REMOTE;
			queue_data(AUX_ACK);
			break;

		case AUX_SET_REMOTE:
			status |= STATUS_REMOTE;
			queue_data(AUX_ACK);
			break;

		case AUX_ENABLE_DEV:
			status |= STATUS_REPORTING;
			queue_data(AUX_ACK);
			break;

		case AUX_DISABLE_DEV:
			status &= ~STATUS_REPORTING;
			queue_data(AUX_ACK);
			break;
			
		case AUX_POLL:
			throw 0;

		default:
			break;
		}
		break;

	case AUX_SET_SAMPLE:
		sample_rate = command;
		last_command = 0;
		queue_data(AUX_ACK);
		break;

	case AUX_SET_RES:
		resolution = command;
		last_command = 0;
		queue_data(AUX_ACK);
		break;

	default:
		last_command = 0;
		break;
	}
}

void PS2MouseDevice::button_down(uint32_t button_index)
{
	button_state |= 1 << button_index;

	send_update();
}

void PS2MouseDevice::button_up(uint32_t button_index)
{
	button_state &= ~(1 << button_index);

	send_update();
}

void PS2MouseDevice::mouse_move(uint32_t x, uint32_t y)
{
	dx = x - last_x;
	dy = y - last_y;

	last_x = x;
	last_y = y;

	send_update();
}

void PS2MouseDevice::send_update()
{
	std::unique_lock<std::mutex> l(process_lock);

	if (!(status & STATUS_REPORTING)) return;
	//if ((status & STATUS_REMOTE)) return;

	if (dx > 127)
		dx = 127;
	else if (dx < -127)
		dx = -127;

	if (dy > 127)
		dy = 127;
	else if (dy < -127)
		dy = -127;

	queue_data(0x08 | ((dx < 0) << 4) | ((dy < 0) << 5) | (button_state & 0x07) );
	queue_data(dx & 0xff);
	queue_data(dy & 0xff);
}
