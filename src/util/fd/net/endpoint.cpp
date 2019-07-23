/* SPDX-License-Identifier: MIT */

#include <util/fd/net/ip-endpoint.h>
#include <util/fd/net/unix-endpoint.h>
#include <malloc.h>
#include <netinet/in.h>
#include <sys/un.h>

using namespace captive::util::fd::net;

EndPoint::EndPoint(AddressFamily af) : _family(af) { }

EndPoint::~EndPoint() {
}

/**
 * Constructs an EndPoint from a given sockaddr.
 * @param sa The sockaddr to construct the EndPoint from.
 * @return An EndPoint representing the given sockaddr.
 */
const EndPoint *EndPoint::from_sockaddr(const struct sockaddr *sa)
{
	// We can only construct endpoints from families we know about.
	if (sa->sa_family == AF_INET) {
		// Create an IPEndPoint
		const struct sockaddr_in *sa_in = (const struct sockaddr_in *)sa;
		return new IPEndPoint(IPAddress(ntohl(sa_in->sin_addr.s_addr)), ntohs(sa_in->sin_port));
	} else if (sa->sa_family == AF_UNIX) {
		// Create a UnixEndPoint
		const struct sockaddr_un *sa_un = (const struct sockaddr_un *)sa;
		return new UnixEndPoint(std::string(sa_un->sun_path));
	} else {
		return NULL;
	}
}

/**
 * Constructs an IPEndPoint from the given IPAddress and port.
 * @param addr The IPAddress to be associated with this endpoint.
 * @param port The port numebr to be associated with this endpoint.
 */
IPEndPoint::IPEndPoint(const IPAddress& addr, int port) : EndPoint(AddressFamily::IPv4), _addr(addr), _port(port)
{

}

IPEndPoint::~IPEndPoint()
{
}

/**
 * Creates a sockaddr from the IPEndPoint.
 * @param len The output length of the sockaddr
 * @return A pointer to a sockaddr.  This must be freed with @free_sockaddr.
 */
struct sockaddr *IPEndPoint::create_sockaddr(socklen_t& len)
{
	// Allocate storage for the sockaddr.
	struct sockaddr_in *sa = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	bzero(sa, sizeof(*sa));
	
	len = sizeof(*sa);

	// Populate the sockaddr.
	sa->sin_family = AF_INET;
	sa->sin_port = htons(_port);
	sa->sin_addr.s_addr = htonl(_addr.address());

	// Return the sockaddr.
	return (struct sockaddr *)sa;
}

/**
 * Releases the memory associated with the given sockaddr.
 * @param sa The sockaddr to free.
 */
void IPEndPoint::free_sockaddr(struct sockaddr *sa)
{
	free(sa);
}

/**
 * Constructs a UnixEndPoint from the given path.
 * @param path The path to the unix domain socket.
 */
UnixEndPoint::UnixEndPoint(std::string path) : EndPoint(AddressFamily::Unix), _path(path)
{
}

UnixEndPoint::~UnixEndPoint()
{
}

/**
 * Creates a sockaddr from the UnixEndPoint.
 * @param len The output length of the sockaddr
 * @return A pointer to a sockaddr.  This must be freed with @free_sockaddr.
 */
struct sockaddr *UnixEndPoint::create_sockaddr(socklen_t& len)
{
	// Allocate storage for the sockaddr.
	struct sockaddr_un *sa = (struct sockaddr_un *)malloc(sizeof(struct sockaddr_in));
	bzero(sa, sizeof(*sa));
	
	// Populate the sockaddr.
	sa->sun_family = AF_UNIX;
	strncpy(sa->sun_path, _path.c_str(), sizeof(sa->sun_path)-1);
			
	// Return the sockaddr.
	return (struct sockaddr *)sa;
}

/**
 * Releases the memory associated with the given sockaddr.
 * @param sa The sockaddr to free.
 */
void UnixEndPoint::free_sockaddr(struct sockaddr *sa)
{
	free(sa);
}
