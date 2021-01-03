#include "Response.hpp"

Server::Response::Response(int status, const std::string& body, const std::string version) :
status(status), body(body), version(version)
{

}

std::stringstream Server::Response::get()
{
	std::stringstream response;

	response << version + " " + std::to_string(status) +  " " + HTTPStatuses::get(status) + "\r\n"
		<< "Version: HTTP/1.1\r\n"
		<< "Content-Type: text/html; charset=utf-8\r\n"
		<< "Content-Length: " << body.length()
		<< "\r\n\r\n"
		<< body;

	return response;
}
