#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <unordered_map>
#include <vector>

// #include "Database.hpp"

using namespace std;

class Server
{
private:
    Server() {}
    static Server *instance;
    int server_fd, new_socket, valread;
	int opt = 1;
	char buffer[4096] = {0};
    vector<double> data;
    void PrintVector(vector<double> v);
    void SplitLine(string s);

public:
    // static unordered_map <string, double> liveData;
    static Server *getInstance();
    void Connect(int port, const char *ip);
    ~Server();
};

#endif