#include "WSA.hpp"

WSADATA* Server::WSA::wsaData = nullptr;

void Server::WSA::init()
{
	wsaData = WSAInit::init();
}

void Server::WSA::free()
{
	WSACleanup();
	delete wsaData;
}

WSADATA Server::WSA::get()
{
	return *wsaData;
}
