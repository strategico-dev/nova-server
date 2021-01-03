#include "ClientSocket.hpp"

Server::ClientSocket::ClientSocket(SOCKET socket) : Socket(socket)
{
	
}

Server::ClientSocket::~ClientSocket()
{
	if (request != nullptr)
	{
		delete request;
	}
}

std::string Server::ClientSocket::getRecv()
{
	if (clientRecv.empty())
	{
		char buffer[BUFFER_SIZE];
		int length = recv(socketDescriptor, buffer, BUFFER_SIZE, 0);

		clientRecv = std::string(buffer);
		clientRecv.resize(length);
	}

	return clientRecv;
}

Server::Request* Server::ClientSocket::getRequest()
{
	if (request == nullptr)
	{
		request = new Request();
		request->load(getRecv());
	}

	return request;
}

void Server::ClientSocket::response(Response& response)
{
	this->response(response.get());
}

void Server::ClientSocket::response(const std::stringstream& data)
{
	if (send(socketDescriptor, data.str().c_str(), data.str().length(), 0) == SOCKET_ERROR)
	{
		throw std::runtime_error("Send failed");
	}
}