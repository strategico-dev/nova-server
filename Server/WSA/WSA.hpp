#pragma once

#include <Server/WSA/WSAInit.hpp>

namespace Server
{
	class WSA
	{
	private:
		static WSADATA* wsaData;
	public:
		static void init();
		static void free();
		static WSADATA get();
	};
}