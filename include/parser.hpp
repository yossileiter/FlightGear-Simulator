#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "Lexer.hpp"
#include "Command.hpp"
#include "Database.hpp"

using namespace std;

class Parser
{
private:
    Parser(){}
    static Parser* instance;
    vector <string> SplitLine(string s);

public:

    static Parser *getInstance();                   //create a singleton
    void Lexing(string filePath);                   //create a lexer and lex the file into vector of vectors
    int parsing(vector<string> line, size_t i);     //take a line and execute the suitable command
    template<typename K, typename V, typename T>
    bool CkeckElementInMap(unordered_map<K,V> const &map, T element);
};

#endif