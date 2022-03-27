#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "Client.cpp"
#include "Server.cpp"

using namespace std;

vector<string> v;
// string s = "openDataServer controls/flight/rudder 1";
string s = "openDataServer 5402 simulator";

// convert the line to strings
void lexer(string s, vector<string> &v)
{	
	string temp = "";
	for(int i=0;i<s.length();++i)
    {
		
		if(s[i]==' ')
        {
			v.push_back(temp);
			temp = "";
		}
		else
        {
			temp.push_back(s[i]);
		}		
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
void checker(string com)
{
    if (com == "openDataServer")
    {
        int port = stoi(v[1]);
        OpenDataServer(port);
    }
    else if (com == "openServer")
    {
        
        int port = stoi(v[1]);
        openServer(port);
    }
    else                    cout<<"Illegal command"<<endl;
}

void parser(vector<string> v)
{
    checker(v[0]);
}

int main()
{
    lexer(s, v);
    parser(v);
    return 0;
}