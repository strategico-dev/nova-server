#include "HTTPStatuses.hpp"

std::map<int, std::string> Server::HTTPStatuses::statuses = {
    {200, "OK"},
    {404, "Not Found"}
};

const int Server::HTTPStatuses::OK = 200;
const int Server::HTTPStatuses::NOT_FOUND = 404;

std::string Server::HTTPStatuses::get(int status)
{
    return statuses[status];
}
