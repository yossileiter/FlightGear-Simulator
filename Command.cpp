#include "Command.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "parser.hpp"

void openServerCommand::doCommand(vector<string> v)
{
  if (v.size() == 2)
  {
    Server *server = Server::getInstance();
    int port = stoi(v[1]);
    const char *ip = "127.0.0.1";
    server->Connect(port, ip);
  }
  else {cout<<"Missing arguments. Enter the port number"<<endl;}
}

void connectCommand::doCommand(vector<string> v)
{
  if (v.size() == 3)
  {
    Client *client = Client::getInstance();
    const char *ip = v[1].c_str();
    int port = stoi(v[2]);
    client->Connect(port, ip);
  }
  else {cout<<"Missing arguments"<<endl;}
}

void varCommand::doCommand(vector<string> v)
{
  // Parser::SymbolTable[v[1]] = {0.0};
}

void bindCommand::doCommand(vector<string> v)
{
  // Parser::getInstance()->VarTable[v[1] = v[4]];
  // Server::getInstance()->VarTable[v[1]] = v[4];
  // server->VarTable[v[1]] = v[4];
  // Server* server2 = Server::getInstance();
  // server2->VarTable[v[1]] = v[4];
}

void setCommand::doCommand(vector<string> v)
{
  Client *client = Client::getInstance();
  // const char *VarPath = v[4].c_str();

}