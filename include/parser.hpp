#ifndef PARSER_H
#define PARSER_H

#define DATABASE Database::getInstance()
#define PARSER Parser::getInstance()

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
    Parser() { DATABASE->buildCommandMap();}
    static Parser *instance;

public:
    static Parser *getInstance();               // create a singleton
    int parsing(vector<string> line, size_t i); // take a line and execute the suitable command
    template <typename K, typename V, typename T>
    bool CkeckIfElementInMap(unordered_map<K, V> const &map, T element);
};

#endif