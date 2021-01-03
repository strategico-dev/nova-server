#pragma once

#include <map>
#include <string>

namespace Server
{
	class RequestParser
	{
	public:
		static std::map<std::string, std::string> parse(const std::string& request);
	};
}