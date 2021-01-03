#pragma once

#include <stdexcept>
#include <Server/Includes/WinSocket.inc.hpp>

namespace Server
{
	class WSAInit
	{
	public:
		static WSADATA* init(int major = 2, int minor = 2);
	};
}