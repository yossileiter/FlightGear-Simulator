#ifndef COMMAND_H
#define COMMAND_H
#include "Server.hpp"
#include "Client.hpp"
// #include "Database.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Command
{
public:
    virtual int doCommand(vector<string> line) = 0;
};

class openServerCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class connectCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class varCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class bindCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class setCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class printCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

class whileCommand : public Command
{
public:
    int doCommand(vector<string> line);
};

#endif