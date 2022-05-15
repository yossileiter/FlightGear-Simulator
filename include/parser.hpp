#ifndef PARSER_H
#define PARSER_H
// #pragma once
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

public:

    static Parser *getInstance();           //create a singleton
    void BuildCommandsMap();                //create commands objects and insert to hash table
    void Lexing();                          //create a lexer and lex the file into vector of vectors
    void parsing(vector<string> line);      //take a line and execute the suitable command
    void PrintVector(vector<string> v);     // print a vector
};

#endif