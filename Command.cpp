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
  else {cout<<"Missing arguments"<<endl;}
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
  // Parser::VarTable[v[1] = {v[4]}];
}