#ifndef COMMAND_H
#define COMMAND_H
#include "Server.hpp"
#include "Client.hpp"
#include "Lexer.hpp"
#include "ShuntingYard.cpp"

#include <chrono>
#include <thread>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Command
{
public:
    virtual void doCommand(vector<string> line, int i) = 0;
    virtual int get_i(int i) = 0;

};

class openServerCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

class connectCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

class varCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

class setCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

class printCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

class whileCommand : public Command
{
private:
    template<typename K, typename V, typename T>
    bool CkeckElementInMap(unordered_map<K,V> const &map, T element);
    bool checkExpression(int x, string op, string y);

public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
    int loopLength;
};

class sleepCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
    virtual int get_i(int i);
};

#endif