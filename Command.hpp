#include "Server.hpp"
#include "Client.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

class Command
{
public:
	virtual void doCommand(vector<string> v) = 0;
};


class openServerCommand : public Command
{
public:
    void doCommand(vector<string> v);
};


class connectCommand : public Command
{
public:
    void doCommand(vector<string> v);
};


class varCommand : public Command
{
public:
    void doCommand(vector<string> v);
};


class bindCommand : public Command
{
public:
    void doCommand(vector<string> v);
};


class setCommand : public Command
{
public:
    void doCommand(vector<string> v);
};