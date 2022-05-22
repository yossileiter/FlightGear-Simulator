#include "Client.hpp"

// #define BUFSIZE 4096

Client *Client::instance = 0;
Client *Client::getInstance()
{
	if (!instance) instance = new Client();
	return instance;
}

void Client::Connect(int port, const char *ip)
{
	struct sockaddr_in serv_addr;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		cout << " Socket creation error" << endl;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
	{
		cout << "Invalid address/ Address not supported" << endl;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		cout << "Connection Failed" << endl;
	}
	cout << "Connection established" << endl;
}

void Client::Send(char *command)
{
	::send(sock, command, strlen(command), 0);
	valread = read(sock, buffer, BUFSIZE);
	cout << buffer << endl;
}
