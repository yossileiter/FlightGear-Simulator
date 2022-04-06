#include "parser.h"
#include "Client.h"
#include "Server.h"

void Lexer::SplitLine(string s)
    {	
        string temp = "";
        for(int i=0 ;i<s.length(); ++i)
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
            cout<<"line "<<i<<": "<<v[i]<<endl;
        cout<<"\n";
    }

void Lexer::ReadInstructions(string FilePath)
{
    fstream newfile;
    newfile.open(FilePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) //checking whether the file is open
    { 
        string line;
        while(getline(newfile, line)) //read data from file object and put it into string.
        { 
            cout << line << "\n"; //print the data of the string  
            AllLines.push_back(line);
        }
        newfile.close(); //close the file object.
    }
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
