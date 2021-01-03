#include "ConfigParser.hpp"

Server::ConfigParser::ConfigParser(std::string path)
{
    config.LoadFile(path.c_str());
}

std::string Server::ConfigParser::getElementValue(const std::string& elementName)
{
    TiXmlElement* element = config.FirstChildElement()->FirstChildElement(elementName.c_str());

    return element->GetText();
}