#include "Request.hpp"

Server::Request::Request(const std::string& data)
{
	load(data);
}

void Server::Request::load(const std::string& data)
{
	std::map<std::string, std::string> result = RequestParser::parse(data);

	method	 = result["method"];
	resource = result["resource"];
	version  = result["version"];
}

std::string Server::Request::getMethod()
{
	return method;
}

std::string Server::Request::getResource()
{
	return resource;
}

std::string Server::Request::getVersion()
{
	return version;
}
