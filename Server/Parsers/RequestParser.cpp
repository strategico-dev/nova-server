#include "RequestParser.hpp"

std::map<std::string, std::string> Server::RequestParser::parse(const std::string& request)
{
    int currentPosition = 0;
    std::map<int, std::string> positions = {
        {0, "method"},
        {1, "resource"},
        {2, "version"}
    };

    std::map<std::string, std::string> result = {};

    std::string value;
    for (char symbol : request)
    {
        if (currentPosition == positions.size())
        {
            break;
        }

        if (symbol == ' ')
        {
            result[positions[currentPosition]] = value;
            value = "";
            currentPosition++;
            continue;
        }

        value += symbol;
    }

    return result;
}
