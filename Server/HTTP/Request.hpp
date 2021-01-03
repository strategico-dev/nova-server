#pragma once

#include <string>

#include <Server/Parsers/RequestParser.hpp>

namespace Server
{
	class Request
	{
	private:
		std::string method;
		std::string resource;
		std::string version;
	public:
		Request() {}
		Request(const std::string& data);

		void load(const std::string& data);

		std::string getMethod();
		std::string getResource();
		std::string getVersion();
	};
}