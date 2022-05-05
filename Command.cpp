#include "Command.hpp"
#include "Server.hpp"
#include "Client.hpp"

void openServerCommand::doCommand(vector<string> v)
{
    Server *server = Server::getInstance();
    int port = stoi(v[1]);
    const char *ip = "127.0.0.1";
    server->Connect(port, ip);
}

void connectCommand::doCommand(vector<string> v)
{
    Client *client = Client::getInstance();
    const char *ip = v[1].c_str();
    int port = stoi(v[2]);
    client->Connect(port, ip);
}