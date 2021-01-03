#include "Address.hpp"

Server::Address::Address(const std::string& host, int port) :
host(host), port(port)
{
	
}

std::string Server::Address::getHost()
{
	return host;
}

int Server::Address::getPort()
{
	return port;
}

sockaddr_in Server::Address::getSocketAddr()
{
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.s_addr = inet_addr(getHost().c_str());
	socketAddr.sin_port = htons(port);

	return socketAddr;
}
