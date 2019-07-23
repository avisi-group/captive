/* SPDX-License-Identifier: MIT */

#include <hypervisor/debugging.h>
#include <util/fd/net/ip-endpoint.h>
#include <util/exception.h>
#include <thread>
#include <string.h>
#include <pthread.h>
#include <malloc.h>

#include <sstream>
#include <iomanip>

using namespace captive::hypervisor;
using namespace captive::util::fd::net;

#define DEBUG_PACKETS
#define STOP_CODE	"T05thread:1;core:0;"

Debugger::Debugger() : _debug_session(nullptr)
{

}

Debugger::~Debugger()
{
	if (_debug_session) {
		delete _debug_session;
	}
}

bool Debugger::init()
{
	_gdb_socket = Socket::create(AddressFamily::IPv4, SocketType::Stream, ProtocolType::None);
	if (!_gdb_socket) return false;
	
	IPEndPoint ipep(IPAddress::any(), 10000);
	try {
		_gdb_socket->reuse_addr(true);
		_gdb_socket->bind(ipep);
	} catch (const captive::util::Exception& ex) {
		fprintf(stderr, "ERROR: %s\n", ex.message().c_str());
		return false;
	}
	
	_gdb_socket->listen(8);
	
	return true;
}

bool Debugger::wait_attach(DebuggerInterface& iface)
{
	Socket *client = nullptr;
	
	while (client == nullptr) {
		client = _gdb_socket->accept();
	}
	
	return start_debug_session(client, iface);
}

bool Debugger::start_debug_session(captive::util::fd::net::Socket* client, DebuggerInterface& iface)
{
	_debug_session = new DebuggerSession(client, iface);
	return _debug_session->start();
}

static bool last;

void Debugger::interrupt()
{
	if (_debug_session != nullptr) {
		_debug_session->interrupt();
		last = false;
	}
}

DebuggerSession::~DebuggerSession()
{
	if (_thread) {
		delete _thread;
	}
}

bool DebuggerSession::start()
{
	pthread_barrier_init(&_ready_barrier, NULL, 2);
	
	_thread = new std::thread(thread_proc_trampoline, this);
	
	pthread_barrier_wait(&_ready_barrier);
	return true;
}

void DebuggerSession::thread_proc_trampoline(void* o)
{
	((DebuggerSession *)o)->thread_proc();
}

void DebuggerSession::thread_proc()
{
	fprintf(stderr, "waiting for initial ack.\n");
	if (!wait_ack()) return;
	pthread_barrier_wait(&_ready_barrier);
	
	while (true) {
		std::string cmd;
		
		if (!read_command(cmd)) break;		
		switch (cmd[0]) {
		case 'q': handle_query_get(cmd); break;
		case 'v': handle_exec_cmd(cmd); break;
		case 'H': send_command("OK"); break;
		case '?': handle_report(); break;
		case 'g': handle_read_registers(); break;
		case 'p': handle_read_register(cmd); break;
		case 'm': handle_read_memory(cmd); break;
		case 'M': send_command("E01"); break;
		case 'c':
			_iface.debug_resume();
			send_stop_code();
			break;
			
		case 's':
			_iface.debug_step();
			send_stop_code();
			break;
			
		default: send_command(""); break;
		}
	}
	
	_client->close();
}

void DebuggerSession::interrupt()
{
	send_command("Stop:" STOP_CODE, '%'); //T05thread:1;", '%');
}

bool DebuggerSession::wait_ack()
{
	char ack_char;
	if (_client->read(&ack_char, 1) == 0) return false;
	return ack_char == '+';
}

void DebuggerSession::send_ack()
{
	char ack_char = '+';
	_client->write(&ack_char, 1);
}

void DebuggerSession::send_nack()
{
	char ack_char = '-';
	_client->write(&ack_char, 1);
}

bool DebuggerSession::read_char(char& c)
{
	size_t bytes_read = _client->read(&c, 1);
	if (bytes_read == 0) return false;

	return true;
}

bool DebuggerSession::read_command(std::string& cmd)
{
	char buffer[256] = {0};
	int offset = 0;
	
	do {
		char ch;
		if (!read_char(ch)) return false;
		
		if (offset == 0 && ch != '$') continue;
		
		buffer[offset] = ch;
		offset++;
	} while (buffer[offset-1] != '#');
	
	char cksum[2];
	if (!read_char(cksum[0])) return false;
	if (!read_char(cksum[1])) return false;
		
	send_ack();

#ifdef DEBUG_PACKETS
	fprintf(stderr, "in pkt: %s\n", buffer);
#endif
	
	cmd = std::string(&buffer[1], offset - 2);
	return true;
}

bool DebuggerSession::send_command(const std::string& command, char starter)
{
	size_t packet_length = command.length() + 4;
	char *packet_buffer = new char[packet_length+1];
	packet_buffer[packet_length] = 0;
	
	packet_buffer[0] = starter;
	
	unsigned char checksum = 0;
	for (unsigned int i = 0; i < command.length(); i++) {
		char c = command[i];
		packet_buffer[i + 1] = c;
		
		checksum += (unsigned char)c;
	}
		
	packet_buffer[packet_length-3] = '#';
	
	int d1 = ((checksum >> 4) & 0xf);
	int d2 = ((checksum >> 0) & 0xf);
	
	if (d1 < 10) {
		packet_buffer[packet_length-2] = '0' + d1;
	} else {
		packet_buffer[packet_length-2] = 'a' + d1 - 10;
	}

	if (d2 < 10) {
		packet_buffer[packet_length-1] = '0' + d2;
	} else {
		packet_buffer[packet_length-1] = 'a' + d2 - 10;
	}
	
#ifdef DEBUG_PACKETS
	fprintf(stderr, "out pkt: %s csum=%02x\n", packet_buffer, checksum);
#endif
	
	_client->write(packet_buffer, packet_length);
	delete[] packet_buffer;
	
	if (starter == '$') {
		return wait_ack();
	} else {
		return true;
	}
}

void DebuggerSession::handle_query_get(const std::string& command)
{
	if (command.compare(0, 10, "qSupported") == 0) {
		send_command("PacketSize=100");
	} else if (command.compare(0, 8, "qTStatus") == 0) {
		send_command("T0;tnotrun:0");
	} else if (command.compare(0, 12, "qfThreadInfo") == 0) {
		send_command("m1");
	} else if (command.compare(0, 12, "qsThreadInfo") == 0) {
		send_command("l");
	} else if (command.compare(0, 4, "qTfV") == 0) {
		send_command("l");
	} else if (command.compare(0, 4, "qTfP") == 0) {
		send_command("l");
	} else if (command.compare(0, 2, "qC") == 0) {
		send_command("QC1");
	} else if (command.compare(0, 9, "qAttached") == 0) {
		send_command("1");
	} else {
		send_command("");
	}
}

void DebuggerSession::handle_exec_cmd(const std::string& command)
{
	if (command.compare(0, 15, "vMustReplyEmpty") == 0) {
		send_command("");
	} else if (command.compare(0, 8, "vStopped") == 0) {
		if (last) {
			send_command("OK");
		} else {
			last = true;
			send_stop_code();
		}
	} else {
		send_command("");
	}
}

void DebuggerSession::handle_report()
{
	send_stop_code();
}

void DebuggerSession::handle_read_registers()
{
	uint64_t regvals[32] = {0};
	size_t count = 32;
	
	if (!_iface.debug_get_registers(regvals, count)) {
		send_command("E01");
		return;
	}
	
	if (count < 18) {
		send_command("E01");
		return;
	}
	
	std::stringstream str;
	for (unsigned int i = 0; i < 17; i++) {
		uint64_t v = htobe64(regvals[i]);
		str << std::hex << std::setw(16) << std::setfill('0') << v;
	}
	
	str << std::hex << std::setw(8) << std::setfill('0') << regvals[17];
	
	send_command(str.str());
}

void DebuggerSession::handle_read_register(const std::string& command)
{
	uint64_t regvals[32] = {0};
	size_t count = 32;

	if (!_iface.debug_get_registers(regvals, count)) {
		send_command("E01");
		return;
	}
	
	unsigned int id;
	sscanf(command.c_str(), "p%02x", &id);
	
	if (id < count) {
		std::stringstream str;
		str << std::hex << std::setw(16) << std::setfill('0') << regvals[id];
		send_command(str.str());
	} else {
		switch (id) {
		case 0x12: send_command("0000"); break;
		case 0x13: send_command("0000"); break;
		case 0x14: send_command("0000"); break;
		case 0x15: send_command("0000"); break;
		case 0x16: send_command("0000"); break;
		case 0x17: send_command("0000"); break;
		default: send_command("E01"); break;
		}
	}
}

void DebuggerSession::handle_read_memory(const std::string& command)
{
	uint64_t addr;
	uint64_t count;
	
	sscanf(command.c_str(), "m%lx,%lx", &addr, &count);
	
	if (count > 0x100) {
		send_command("E01");
		return;
	}
	
	char *mem = (char *)malloc(count);
	if (!mem) {
		send_command("E01");
		return;
	}
	
	if (!_iface.debug_get_memory(addr, mem, count)) {
		free(mem);
		send_command("E01");
		return;
	}
	
	std::stringstream str;
	for (unsigned int i = 0; i < count; i++) {
		str << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)(unsigned char)mem[i];
	}
	
	free(mem);
	
	send_command(str.str());
}

void DebuggerSession::send_stop_code()
{
	//send_command(STOP_CODE);
	
	std::stringstream str;
	str << "T05";
	
	uint64_t regvals[32] = {0};
	size_t count = 32;

	if (!_iface.debug_get_registers(regvals, count)) {
		send_command("E01");
		return;
	}
	
	str << "06:" << std::hex << std::setw(16) << std::setfill('0') << htobe64(regvals[6]) << ";";
	str << "07:" << std::hex << std::setw(16) << std::setfill('0') << htobe64(regvals[7]) << ";";
	str << "10:" << std::hex << std::setw(16) << std::setfill('0') << htobe64(regvals[16]) << ";";
	
	str << "thread:1;core:0;";
	
	send_command(str.str());
}
