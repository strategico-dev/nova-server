#pragma once

#include <fstream>
#include <sys/stat.h>

namespace Server
{
	class File
	{
	private:
		std::ifstream file;
	public:
		File() {}
		~File();

		void open(const std::string& path);

		std::string read();

		static bool exists(const std::string& path);
	};
}