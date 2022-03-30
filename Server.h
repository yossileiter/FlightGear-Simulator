#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

// int server(int port);

using namespace std;

class Server
{
private:
    static Server* instance;

public:
    Server() {};
    Server* getInstance()
    {
        if (instance == 0) instance = new Server();
        return instance;
    }
	void Connect(int port, const char* ip);
    ~Server();
};