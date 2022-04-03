#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<string> v;
// string s = "client 5402 127.0.0.1";
string s = "server 5400 127.0.0.1";


class Lexer
{
private:

public:
    Lexer(){}
    void lex(string s);
    void PrintVector(vector<string> v);
};

class Parser
{
public:
    void parse(vector<string> v);
    
};