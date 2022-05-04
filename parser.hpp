#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


class Parser
{
public:
    void LetsLex();   
    void parsing(vector<string> v);
};



class Command
{
public:
	virtual void doCommand(vector<string> v) = 0;
};

class openServerCommand : public Command
{
public:
    void doCommand(vector<string> v) override;
};

class connectCommand : public Command
{
public:
    void doCommand(vector<string> v);
};
