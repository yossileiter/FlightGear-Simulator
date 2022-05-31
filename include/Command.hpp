#ifndef COMMAND_H
#define COMMAND_H
#include "Server.hpp"
#include "Client.hpp"
#include "Lexer.hpp"
#include "ShuntingYard.cpp"

#include <chrono>
#include <thread>
#include <stdio.h>
#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Command
{
public:
    virtual void doCommand(vector<string> line, int i) = 0;
    virtual int get_i(int i) { return i; }
    double getVarValue(string var);
    template <typename K, typename V, typename T>
    bool CkeckIfElementInMap(unordered_map<K, V> const &map, T element);
};

class openServerCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

class connectCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

class varCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

class setCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

class printCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

class whileCommand : public Command
{
private:

    bool checkExpression(double x, string op, string y);
    bool FindIfElementExist(vector<string> v, string element);
    int FindElementLocation(vector<vector<string>> v, string element, int i);

public:
    void doCommand(vector<string> line, int i);
    int get_i(int i) { return i += loopLength; } // increase the i by amount of while lines
    int loopLength;
};

class sleepCommand : public Command
{
public:
    void doCommand(vector<string> line, int i);
};

#endif