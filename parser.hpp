#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
// #include <thread>

using namespace std;


class Parser
{
public:
    static unordered_map <string, double> SymbolTable;
    static unordered_map <string, string> VarTable;
    void LetsLex();                 //create a lexer and lex the file into vector of vectors
    void parsing(vector<string> v); //take a line and execute the suitable command
};
