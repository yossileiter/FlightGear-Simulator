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

using namespace std;

class Parser
{
private:
    Parser(){}
    static Parser* instance;

public:
    unordered_map <string, Command*> CommandMap;        //key: command NAME, value: command OBJECT
    static unordered_map <string, double> SymbolTable;  //key: Flight DEVICES, value: VALUE in numbers
    static unordered_map <string, string> VarTable;     //key: Flight device NAME, value: Flight device PATH

    static Parser *getInstance();   //create a singleton
    void BuildCommandsMap();        //create commands objects and insert to hash table
    void Lexing();                  //create a lexer and lex the file into vector of vectors
    void parsing(vector<string> line); //take a line and execute the suitable command
};

#endif