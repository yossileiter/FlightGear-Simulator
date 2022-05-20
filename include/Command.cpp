#include "Command.hpp"
#include "Database.hpp"     //this include can't work from header file

void openServerCommand::doCommand(vector<string> line)
{
    if (line.size() == 2)
    {
        int port = stoi(line[1]);
        const char *ip = "127.0.0.1";
        Server::getInstance()->Connect(port, ip);
    }
    else {cout<<"open data server - Missing arguments"<<endl;}
}

void connectCommand::doCommand(vector<string> line)
{
    if (line.size() == 3)
    {
        const char *ip = line[1].c_str();
        int port = stoi(line[2]);
        Client::getInstance()->Connect(port, ip);
    }
    else {cout<<"connect - Missing arguments"<<endl;}
}


void varCommand::doCommand(vector<string> line)
{
    if ((line[3] == "bind") && (line.size() == 5))  //bind a new var
    {
        Database::getInstance()->VarTable[line[1]] = line[4];
        cout << "'" << line[1] << "' bound successfully!" << endl;
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        double valueForNewVar;
        string devicePath = Database::getInstance()->VarTable[line[3]];         //get device path from var table
        // const char * devicePath2 = devicePath.c_str();
        cout<<"device path:"<<devicePath<<endl;
        // cout << "d2: "<<Database::getInstance()->VarTable["heading"]<<endl;
        valueForNewVar = Database::getInstance()->SymbolTable[devicePath];      //get current value of the device
        cout <<"value of heading: "<<Database::getInstance()->SymbolTable["/instrumentation/heading-indicator/offset-deg"]<<endl;
        const char* devicePath3 = devicePath.c_str();
        cout <<"value of heading 2: "<<Database::getInstance()->SymbolTable[devicePath3]<<endl;
        Database::getInstance()->SymbolTable[line[1]] = valueForNewVar;         //insert the new var as key and current value as value
        // cout<<Database::getInstance()->SymbolTable[devicePath] <<endl;
        cout << "'" << line[1] << "' was successfully inserted!" << endl;
    }
    else if (line.size() == 3)                      //set command
    {
        // cout<<"three: "<<endl;
        string stringSet = "ls\r\n";
        stringSet += "set ";
        stringSet += Database::getInstance()->VarTable.at(line[0]);
        stringSet += line[2];
        // stringSet += "\r\n";
        char* newStringSet = &stringSet[0];
        Client::getInstance()->Send(newStringSet);
    }
    else {cout << "Illegal command" << endl;}
}

void printCommand::doCommand(vector<string> line)
{
    if (line[1].find("")) { }
}

void whileCommand::doCommand(vector<string> line)
{
    if (line[1].find("{")) { }
}

void bindCommand::doCommand(vector<string> line)
{
    
}