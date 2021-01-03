#include "Socket.hpp"

Server::Socket::Socket(SOCKET socket)
{
    socketDescriptor = socket;
}

Server::Socket::Socket(Address* address) : address(address)
{
    socketDescriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketDescriptor == INVALID_SOCKET)
    {
        throw std::runtime_error("Socket failed");
    }

    sockaddr_in sockAddrIn = address->getSocketAddr();
    if (bind(socketDescriptor, (SOCKADDR*)&sockAddrIn, sizeof(sockAddrIn)) == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        throw std::runtime_error("Bind failed");
    }
}

Server::Socket::~Socket()
{
    if (address)
    {
        delete address;
    }

    closesocket(socketDescriptor);
}

int Server::Socket::get()
{
    return socketDescriptor;
}
