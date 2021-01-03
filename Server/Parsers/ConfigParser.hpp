#pragma once

#include <string>

#include <TinyXML/tinyxml.h>

namespace Server
{
	class ConfigParser
	{
	private:
		TiXmlDocument config;
	public:
		ConfigParser(std::string path);

		std::string getElementValue(const std::string& elementName);
	};
}