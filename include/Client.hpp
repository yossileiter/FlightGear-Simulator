#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define BUFSIZE 4096

using namespace std;

class Client
{
private:
    Client() {}
    static Client *instance;
    int sock = 0, valread;
    char buffer[BUFSIZE] = {0};

public:
    static Client *getInstance();
    void Connect(int port, const char *ip);
    void Send(char *command);
    ~Client();
};
