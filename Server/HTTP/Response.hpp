#pragma once

#include <string>
#include <sstream>

#include <Server/HTTP/HTTPStatuses.hpp>

namespace Server
{
	class Response
	{
	private:
		int status;
		std::string version;
		std::string body;
	public:
		Response(int status, const std::string& body, const std::string version = "HTTP/1.1");

		std::stringstream get();
	};
}