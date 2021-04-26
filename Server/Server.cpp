#include "Server.hpp"

Server::Server::Server() :
serverSocket(
ServerSocket(
	new Address("127.0.0.1", 1111)
))
{
	
}

Server::Server::~Server()
{
	WSA::free();
}

void Server::Server::handle(ClientSocket* clientSocket)
{
	Request* request = clientSocket->getRequest();

	std::string resource = request->getResource();
	if (resource == Resource::index)
	{
		resource = Config::get()->getIndex();
	}

	resource = Resource::getFullPath(resource);

	File file;
	int status = HTTPStatuses::OK;

	if (File::exists(resource))
	{
		file.open(resource);
	}
	else
	{
		status = HTTPStatuses::NOT_FOUND;
		file.open(Config::get()->getNotFoundPage());
	}

	Response response(status, file.read());
	clientSocket->response(response);

	delete clientSocket;
}

void Server::Server::run()
{
	while (true)
	{
		ClientSocket* clientSocket = serverSocket.acceptSocket();
	
		std::thread handleThread([&]() {
			handle(clientSocket);
		});

		handleThread.join();
	}
}
