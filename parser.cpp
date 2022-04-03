#include "parser.h"
#include "Client.h"
#include "Server.h"

void Lexer::lex(string s)
    {	
        string temp = "";
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ')
            {
                v.push_back(temp);
                temp = "";
            }
            else { temp.push_back(s[i]); }		
        }
        v.push_back(temp);	
    };

void Lexer::PrintVector(vector<string> v)
    {
        for(int i=0;i<v.size();++i)
            cout<<v[i]<<endl;
        cout<<"\n";
    }

void Parser::parse(vector<string> v)
{
    string command = v[0];
    
    if (command == "client")
    {
        static Client *client = new Client;
        int port = stoi(v[1]);
        const char* ip = v[2].c_str();
        // Client client = Client::getInstance()->Connect(port, ip);
        // Client::getInstance()->Connect(port, ip);
        client->Connect(port, ip);
        // client
        
    }
    else if (command == "server")
    {
        Server *server = new Server();
        int port = stoi(v[1]);
        const char* ip = v[2].c_str();
        // server->getInstance()->Connect(port, ip);
        server->Connect(port, ip);
    }
    else    cout<<"Illegal command"<<endl;
}