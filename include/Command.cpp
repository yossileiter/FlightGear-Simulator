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
    if ((line[3] == "bind") && (line.size() == 5))          //bind command
    {
       Database::getInstance()->VarTable[line[1]] = line[4];
        cout << line[1] << " bound successfully!" << endl;
    }   
    else if (line.size() == 4)                             //assignment
    {
        //for var h0 = 1
    }
    else if (line.size() == 3)                             //set command
    {
        string stringSet;
        stringSet += "set ";
        stringSet += Database::getInstance()->VarTable.at(line[0]);
        stringSet += line[2];
        stringSet += "\r\n";
        // to do: change stringSet to char*
    }
    else {cout << "Illegal command" << endl;}
}

void printCommand::doCommand(vector<string> line)
{
    if (line[1].find("""")) { }
}

void whileCommand::doCommand(vector<string> line)
{

}

void bindCommand::doCommand(vector<string> line)
{
    
}