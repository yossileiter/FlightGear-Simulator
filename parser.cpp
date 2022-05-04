#include "parser.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "Lexer.hpp"


void openServerCommand::doCommand(vector<string> v) 
{
    Server *server = Server::getInstance();
    int port = stoi(v[1]);
    const char* ip = "127.0.0.1";
    server->Connect(port, ip);

}

void connectCommand::doCommand(vector<string> v)
{
    Client *client = Client::getInstance();
    const char* ip = v[1].c_str();
    int port = stoi(v[2]);
    client->Connect(port, ip);
}

void Parser::parse()
{
    static Lexer *lexer = new Lexer;
    lexer->ReadInstructions("FlightInstructions.txt"); 
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        lexer->SplitLine(lexer->AllLines[i]);
        lexer->AllLinesSeparated.push_back(lexer->v);
    }
    parsing(lexer->AllLinesSeparated[0]);
    delete lexer;
}

void Parser::parsing(vector<string> vec)
{
    string command = vec[0];
    if (command == "connect")
    {
        
        connectCommand *ConnectCommand = new connectCommand();
        ConnectCommand->doCommand(vec);
    }
    else if (command == "openDataServer")
    {
        openServerCommand *OpenServerCommand = new openServerCommand();
        OpenServerCommand->doCommand(vec);    
        
    }
    else    cout<<"Illegal command"<<endl;
}

