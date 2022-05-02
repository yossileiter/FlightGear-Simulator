#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <fstream>

// int server(int port);

using namespace std;

class Server
{
private:
    Server(){}
    static Server* instance;

public:
    static Server* getInstance();
	void Connect(int port, const char* ip);
    ~Server();
};