#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Client.h"

// #define PORT 5402
#define BUFSIZE 4096

using namespace std;

// int OpenDataServer(int argc, char const *argv[])
int client(int port)
{
	int sock = 0, valread, counter = 0;
	struct sockaddr_in serv_addr;
	
	
	char *hello = "ls\r\nls\r\nset controls/flight/rudder 1\r\nls\r\n";
    char *hello2 = "set controls/flight/rudder 1\r\n";
	char *hello3 = "set controls/flight/rudder -1\r\n";
	char *hello4 = "set controls/flight/rudder 1\r\n";
	char *hello5 = "set controls/flight/rudder -1\r\nls\r\n";
	char buffer[BUFSIZE] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
    
    size_t len = strlen(hello);


	while (1)
	{
		// char* str;
		// cin >> str;
		// cout<<"str is: "<<str;
		// send(sock , str , strlen(str) , 0 );
		// sleep(1);
		send(sock , hello2 , strlen(hello2) , 0 );
		sleep(1);
		send(sock , hello3 , strlen(hello3) , 0 );
		sleep(1);
		send(sock , hello4 , strlen(hello4) , 0 );
		sleep(1);
		send(sock , hello5 , strlen(hello5) , 0 );
		valread = read( sock , buffer, BUFSIZE);
		printf("%s\n",buffer );
		printf("valread is: %d\n",valread);
		printf("counter is: %d\n", counter++);
	}
	return 0;
}

