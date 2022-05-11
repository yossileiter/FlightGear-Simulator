// #pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include "Server.hpp"
#include "Client.hpp"
// #include "parser.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Command
{
public:
    virtual void doCommand(vector<string> line) = 0;
};

class openServerCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

class connectCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

class varCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

class bindCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

class setCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

class printCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

#endif