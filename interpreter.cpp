#include "Client.h"
#include "Server.h"
// #include "parser.cpp"

using namespace std;

vector<string> v;
string s = "client 5402 127.0.0.1";
// const char* ip = "127.0.0.1";

// convert the line to strings
void lexer(string s)
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
}

void PrintVector(vector<string> v)
{
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;
	cout<<"\n";
}

// check the command
void commander(string command)
{
    if (command == "client")
    {
        Client *client = new Client();
        int port = stoi(v[1]);
        const char* ip = v[2].c_str();
        cout<<"ip: "<<ip<<endl;
        client->Connect(port, ip);
    }
    else if (command == "server")
    {
        Server *server = new Server();
        int port = stoi(v[1]);
        const char* ip = v[2].c_str();
        server->Connect(port, ip);
    }
    else    cout<<"Illegal command"<<endl;
}

void parser(vector<string> v)
{
    commander(v[0]);
}

int main()
{
    lexer(s);
    
    PrintVector(v);
    parser(v);
    return 0;
}