#include "Command.hpp"
#include "Database.hpp"     //this include can't work from header file

template<typename K, typename V>
void PrintMap(unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "  {" << pair.first << ": " << pair.second << "}\n";
    }
}

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
        line[4].pop_back();
        line[4].erase(0,1);
        Database::getInstance()->VarTable[line[1]] = line[4];
        cout << "'" << line[1] << "' bound successfully!" << endl;
        // PrintMap(Database::getInstance()->VarTable);        
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        double valueForNewVar;
        string devicePath = Database::getInstance()->VarTable[line[3]];         //get device path from var table
        valueForNewVar = Database::getInstance()->SymbolTable[devicePath];      //get current value of the device
        Database::getInstance()->SymbolTable[line[1]] = valueForNewVar;         //insert the new var as key and current value as value
        cout<<"Value of '"<< line[1] <<"' is: "<<Database::getInstance()->SymbolTable[devicePath];
        cout << " and successfully inserted!" << endl;
        // PrintMap(Database::getInstance()->SymbolTable);
    }
    else {cout << "Illegal command" << endl;}
}

void printCommand::doCommand(vector<string> line)
{
    if (line[1].find(R"("")"))
    {
        line[1].erase(0,1);
        line[1].pop_back();
        cout << line[1] <<endl;
    }
    else { cout <<"not found"<<endl;}
}

void whileCommand::doCommand(vector<string> line)
{
    if (line[1].find("{")) { }
}

void setCommand::doCommand(vector<string> line)
{
    if (line.size() == 3)
    {
        string stringSet = "set ";
        stringSet += Database::getInstance()->VarTable[line[0]] + " " + line[2] + "\r\n";
        cout << stringSet << endl;
        char* newStringSet = &stringSet[0];
        Client::getInstance()->Send(newStringSet);
    }
    else {cout << "Illegal command" << endl;}
}

void sleepCommand::doCommand(vector<string> line)
{
    if (line.size() == 2)
    {
        this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
        cout << "Waiting " << line[1] << " milliseconds" << endl;
    }
    else cout << "Illegal command" << endl;
}