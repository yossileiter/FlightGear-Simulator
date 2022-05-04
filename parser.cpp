#include "parser.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "Lexer.hpp"


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
            AllLines.push_back(line);
        }
        cout<<"newAllLines.size() after ReadInstructions() is: "<<AllLines.size()<<endl;
        newfile.close(); //close the file object.
    }
}

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

