#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

class Client
{
private:
    Client(){}
    static Client* instance;

public:
    static Client *getInstance();
	void Connect(int port, const char* ip);
    ~Client();
};

