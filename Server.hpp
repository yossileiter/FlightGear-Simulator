#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <unordered_map>


// int server(int port);

using namespace std;

class Server
{
private:
    Server() {}
    static Server *instance;

public:
    static Server *getInstance();
    // static unordered_map<string, double> SymbolTable;
    // static unordered_map<string, string> VarTable;
    void Connect(int port, const char *ip);
    ~Server();
};