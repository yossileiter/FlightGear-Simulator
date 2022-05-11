#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <unordered_map>

using namespace std;

class Server
{
private:
    Server() {}
    static Server *instance;

public:
    static Server *getInstance();
    void Connect(int port, const char *ip);
    ~Server();
};