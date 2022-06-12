#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "configuration.cpp"
#include "Lexer.hpp"
#include "Command.hpp"
#include "Database.hpp"

using namespace std;

class Parser
{
public:
    Parser() { DATABASE->buildCommandMap();}
    int parsing(const vector<string> &line, size_t i); // take a line and execute the suitable command
    template <typename K, typename V, typename T>
    bool CheckIfElementInMap(unordered_map<K, V> const &map, T element);
};

#endif