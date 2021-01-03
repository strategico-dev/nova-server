#pragma once

#include <Server/Socket/Socket.hpp>
#include <Server/Socket/ClientSocket.hpp>
#include <Server/Includes/WinSocket.inc.hpp>

namespace Server
{
	class ServerSocket : public Socket
	{
	public:
		ServerSocket(Address* address);
		virtual ~ServerSocket() {}

		ClientSocket* acceptSocket();
	};
}