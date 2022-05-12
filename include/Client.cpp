#include "Client.hpp"

#define BUFSIZE 4096

Client* Client::instance = 0;
Client* Client::getInstance()
{
	if(!instance) instance = new Client();
	return instance;	
}

void Client::Connect(int port, const char* ip)
{
	char *CommandString = (char*)"ls\r\n";
	
	int sock = 0, valread, counter = 0;
	struct sockaddr_in serv_addr;
	char buffer[BUFSIZE] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
	}
	while (1)
	{
		send(sock , CommandString , strlen(CommandString) , 0 );
		valread = read( sock , buffer, BUFSIZE);
		printf("%s\n",buffer );
		printf("counter is: %d\n", counter++);
	}
	

}