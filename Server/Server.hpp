#pragma once

#include <thread>
#include <iostream>

#include <Server/WSA/WSA.hpp>
#include <Server/File/File.hpp>
#include <Server/HTTP/Resource.hpp>
#include <Server/HTTP/Response.hpp>
#include <Server/HTTP/HTTPStatuses.hpp>
#include <Server/Socket/ServerSocket.hpp>

namespace Server
{
	class Server
	{
	private:
		ServerSocket serverSocket;

		void handle(ClientSocket* clientSocket);
	public:
		Server();
		~Server();

		void run();
	};
}