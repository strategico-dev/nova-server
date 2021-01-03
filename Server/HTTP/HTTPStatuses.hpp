#pragma once

#include <map>
#include <string>

namespace Server
{
	class HTTPStatuses
	{
	private:
		static std::map<int, std::string> statuses;
	public:
		static const int OK;
		static const int NOT_FOUND;

		static std::string get(int status);
	};
}