#include <stdio.h>
#include <vector>
#include <iostream>

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