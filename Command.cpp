#include "Command.hpp"

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
  if ((v[3] == "bind") && (v.size() == 5))
  {
    // Parser::getInstance()->VarTable[v[1]] = v [4];
    cout << v[1] << " bound successfully!" << endl;
  }
  else if (v.size() == 4)
  {
    //for var h0 = 1
  }
  else {cout << "Illegal command" << endl;}
}

void setCommand::doCommand(vector<string> v)
{
  // Client *client = Client::getInstance();
  // Parser::getInstance()->VarTable[v[0]];
  string stringSet;
  stringSet += "set ";
  // stringSet += Parser::getInstance()->VarTable.at(v[0]);
  stringSet += v[2];
  stringSet += "\r\n";
  // to do: change stringSet to char*
}