#include "ServerSocket.hpp"

Server::ServerSocket::ServerSocket(Address* address) : Socket(address)
{
    if (listen(socketDescriptor, SOMAXCONN) == SOCKET_ERROR)
    {
        throw std::runtime_error("Listen failed");
    }
}

Server::ClientSocket* Server::ServerSocket::acceptSocket()
{
    int clientSocket = accept(socketDescriptor, NULL, NULL);

    if (clientSocket == INVALID_SOCKET)
    {
        throw std::runtime_error("Accept failed");
    }

    return new ClientSocket(clientSocket);
}