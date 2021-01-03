#include "WSAInit.hpp"

WSADATA* Server::WSAInit::init(int major, int minor)
{
    WSADATA* wsaData = new WSADATA;
    if (WSAStartup(MAKEWORD(major, minor), wsaData) != 0)
    {
        throw std::runtime_error("WSAInit failed");
    }

    return wsaData;
}
