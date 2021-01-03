#include <Server/Server.hpp>
#include <Server/WSA/WSA.hpp>

int main()
{
	Server::WSA::init();

	(Server::Server()).run();

	return 0;
}