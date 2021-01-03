#pragma once

#include <string>
#include <stdexcept>
#include <Server/Socket/Address.hpp>
#include <Server/Includes/WinSocket.inc.hpp>

namespace Server
{
	class Socket
	{
	protected:
		SOCKET socketDescriptor;
		Address* address;
	public:
		Socket() {}
		Socket(SOCKET socket);
		Socket(Address* address);
		~Socket();

		int get();
	};
}