#pragma once

#include <sstream>
#include <Server/HTTP/Request.hpp>
#include <Server/Socket/Socket.hpp>
#include <Server/HTTP/Response.hpp>

#define BUFFER_SIZE 1024

namespace Server
{
	class ClientSocket : public Socket
	{
	private:
		std::string clientRecv;
		Request* request;
	public:
		ClientSocket(SOCKET socket);
		virtual ~ClientSocket();

		std::string getRecv();
		Request* getRequest();

		void response(Response& response);
		void response(const std::stringstream& data);
	};
}