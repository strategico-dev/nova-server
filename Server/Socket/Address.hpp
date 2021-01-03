#pragma once

#pragma warning(disable:4996) 

#include <string>
#include <Server/Includes/WinSocket.inc.hpp>

namespace Server
{
	class Address
	{
	private:
		std::string host;
		int port;
		sockaddr_in socketAddr;
	public:
		Address(const std::string& host, int port);
		
		std::string getHost();
		int getPort();
		sockaddr_in getSocketAddr();
	};
}