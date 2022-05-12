#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include <unordered_map>
#include "Command.hpp"
// #include "parser.hpp"

using namespace std;

class Database
{
private:
    Database(){}
    static Database* instance;

public:
    static unordered_map<string, Command*> CommandMap;      // key: command NAME, value: command OBJECT
    static unordered_map<string, double> SymbolTable; // key: Flight DEVICES, value: VALUE in numbers
    static unordered_map<string, string> VarTable;    // key: Flight device NAME, value: Flight device PATH

    static Database *getInstance();   
    void buildmap();     
};

#endif