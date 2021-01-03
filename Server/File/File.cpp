#include "File.hpp"

Server::File::~File()
{
	file.close();
}

void Server::File::open(const std::string& path)
{
	file.open(path);
}

std::string Server::File::read()
{
	return std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>()
	);
}

bool Server::File::exists(const std::string& path)
{
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}
