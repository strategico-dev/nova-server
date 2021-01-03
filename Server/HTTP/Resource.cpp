#include "Resource.hpp"

const std::string Server::Resource::index = "/";

std::string Server::Resource::getFullPath(const std::string resource)
{
	return Config::get()->getSource() + resource;
}
