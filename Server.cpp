#include "Server.hpp"
#include <fstream>
// #define PORT 5400

void Server::Connect(int port, const char* ip)
{
	// cout<<"testing"<<endl;
	int server_fd, new_socket, valread, counter = 0;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[4096] = {0};
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// Forcefully attaching socket to the port PORT
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( port );
	
	// Forcefully attaching socket to the port PORT
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	while (1) 
	{
		valread = read( new_socket , buffer, 4096);
		ofstream myfile ("DataBase.txt");
		if (myfile.is_open())
		{
			myfile << buffer<<endl;
			myfile.close();
		}
		else cout << "Unable to open file";
			
		
		printf("%s\n",buffer );
		printf("counter is: %d\n", counter++);
	}

}

