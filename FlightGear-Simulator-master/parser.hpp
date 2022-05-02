#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<string> AllLines, v;
vector<vector<string>> AllLinesSeparated;
// string s = "client 5402 127.0.0.1";
// string s = "server 5400 127.0.0.1";


class Lexer
{
private:

public:
    Lexer(){}
    void ReadInstructions(string FilePath);
    void SplitLine(string s);
    void PrintVector(vector<string> v);
};


class Parser
{
public:
    void parse(vector<string> v);    
};

class Command
{
public:
	virtual void doCommand() = 0;
};

class openServerCommand : public Command
{
public:
    void doCommand();
};

class connectCommand : public Command
{
public:
    void doCommand();
};