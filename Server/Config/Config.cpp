#include "Config.hpp"

Server::Config* Server::Config::config = nullptr;

Server::Config* Server::Config::get()
{
    if (config == nullptr)
    {
        config = new Config();
    }

    return config;
}

void Server::Config::free()
{
    if (config == nullptr)
    {
        delete config;
    }
}

Server::Config::Config(const std::string path) : configParser(ConfigParser(path))
{
    
}

std::string Server::Config::getHost()
{
    if (host.empty())
    {
        host = configParser.getElementValue("Host");
    }

    return host;
}

int Server::Config::getPort()
{
    if (!port)
    {
        port = std::stoi(configParser.getElementValue("Port"));
    }

    return port;
}

std::string Server::Config::getSource()
{
    if (source.empty())
    {
        source = configParser.getElementValue("Source");
    }

    return source;
}

std::string Server::Config::getIndex()
{
    if (index.empty())
    {
        index = configParser.getElementValue("Index");
    }

    return index;
}

std::string Server::Config::getNotFoundPage()
{
    if (notFoundPage.empty())
    {
        notFoundPage = configParser.getElementValue("NotFoundPage");
    }

    return notFoundPage;
}
