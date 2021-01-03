#pragma once

#include <string>

#include <Server/Parsers/ConfigParser.hpp>

namespace Server
{
	class Config
	{
	private:
		static Config* config;

		ConfigParser configParser;

		std::string host;
		int port;
		std::string source;
		std::string index;
		std::string notFoundPage;
	public:
		static Config* get();
		static void free();

		Config(const std::string path = "config.xml");

		std::string getHost();
		int getPort();
		std::string getSource();
		std::string getIndex();
		std::string getNotFoundPage();
	};
}