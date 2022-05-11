#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "Lexer.hpp"
#include "Command.hpp"

using namespace std;


class Parser
{
private:
    Parser(){}
    static Parser* instance;

public:
    static unordered_map <string, double> SymbolTable;
    static unordered_map <string, string> VarTable;
    unordered_map <string, Command*> CommandMap;

    static Parser *getInstance();   //create a singleton
    void LetsLex();                 //create a lexer and lex the file into vector of vectors
    void parsing(vector<string> v); //take a line and execute the suitable command
};
