#pragma once

#include <string>

#include <Server/Config/Config.hpp>

namespace Server
{
	class Resource
	{
	public:
		static const std::string index;

		static std::string getFullPath(const std::string resource);
	};
}