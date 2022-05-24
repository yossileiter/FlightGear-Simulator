#include "Command.hpp"
#include "Database.hpp"     //this include can't work from header file
#include "parser.hpp"

template<typename K, typename V>
void PrintMap(unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "  {" << pair.first << ": " << pair.second << "}\n";
    }
}

void openServerCommand::doCommand(vector<string> line, int i)
{
    if (line.size() == 2)
    {
        int port = stoi(line[1]);
        const char *ip = "127.0.0.1";
        Server::getInstance()->Connect(port, ip);
        // Server::getInstance()->ListeningToSimulator();
    }
    else {cout<<"open data server - Missing arguments"<<endl;}
}

void connectCommand::doCommand(vector<string> line, int i)
{
    if (line.size() == 3)
    {
        const char *ip = line[1].c_str();
        int port = stoi(line[2]);
        Client::getInstance()->Connect(port, ip);
    }
    else {cout<<"connect - Missing arguments"<<endl;}
}


void varCommand::doCommand(vector<string> line, int i)
{
    if ((line[3] == "bind") && (line.size() == 5))  //bind a new var
    {   
        line[4].pop_back();
        line[4].erase(0,1);
        Database::getInstance()->VarTable[line[1]] = line[4];       //insert to var table
        cout << "'" << line[1] << "' bound successfully!" << endl;
        // PrintMap(Database::getInstance()->VarTable);        
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        double valueForNewVar;
        string devicePath = Database::getInstance()->VarTable[line[3]];         //get device path from var table
        valueForNewVar = Database::getInstance()->SymbolTable[devicePath];      //get current value of the device
        Database::getInstance()->SymbolTable[line[1]] = valueForNewVar;         //insert the new var as key and current value as value
        cout << "'" << line[1] << "' Successfully inserted" << endl;
        // cout<<"Value of '"<< line[1] <<"' is: "<<Database::getInstance()->SymbolTable[devicePath];
        // cout << " and successfully inserted!" << endl;
        // PrintMap(Database::getInstance()->SymbolTable);
    }
    else {cout << "Illegal command" << endl;}
}

void printCommand::doCommand(vector<string> line, int i)
{
    if (line[1].find("\""))         //find "" in the line and remove it
    {
        line[1].erase(0,1);
        line[1].pop_back();
        cout << line[1] << endl;
    }
    else                            //print a variable
    {
        string path = Database::getInstance()->VarTable[line[1]]; 
        // cout << path <<endl;
        double value = Database::getInstance()->SymbolTable[path];
        // cout << value <<endl;
        cout << line[1] << ": " << value << endl;
    }
}


void whileCommand::doCommand(vector<string> line, int i)
{
    // if (line[1].find("{")) { }
    cout<<"WHILE LOOP!!!\t\t";
    cout <<"original size: "<<Lexer::getInstance()->AllLinesSeparated.size()<<" |\t";
    
    if (CkeckElementInMap(Database::getInstance()->VarTable, line[1]) == 0)   //if var exist in var table
    {
        vector<vector<string>> whileLines;
        double varValue;
        string devicePath = Database::getInstance()->VarTable[line[1]];         //get device path from var table
        varValue = Database::getInstance()->SymbolTable[devicePath];            //get the variable value
        int location = Lexer::getInstance()->FindElementLocation(Lexer::getInstance()->AllLinesSeparated, "}");
        cout<<"location: "<<location<<endl;
        cout<<"i: "<<i<<endl;
        for (size_t j = i+1; j < location; j++)
        {   
            cout<<"j: "<<j<<endl;
            whileLines.push_back(Lexer::getInstance()->AllLinesSeparated[j]);
            cout << "insert line: "<<Lexer::getInstance()->AllLinesSeparated[j][0] <<" "<<Lexer::getInstance()->AllLinesSeparated[j][1]<<endl;
            // Lexer::getInstance()->AllLinesSeparated[j].clear();             //clear the original vector 
            cout <<"big vector: " <<Lexer::getInstance()->AllLinesSeparated.size()<<"\n";    
            // Lexer::getInstance()->AllLinesSeparated.erase(Lexer::getInstance()->AllLinesSeparated.begin());

        }
        
        cout <<"left vector: " <<Lexer::getInstance()->AllLinesSeparated.size()<<" |\t";    
        cout <<"while lines: "<<whileLines.size()<<endl;                                               
        
        for (size_t k = 0; k < whileLines.size(); k++)
        {
            cout << "parsing line: "<<whileLines[k][0] <<" "<<whileLines[k][1]<<endl;
            Parser::getInstance()->parsing(whileLines[k], 100);
        }
    }
    else cout << "Variable not found" << endl;
}

template<typename K, typename V, typename T>
bool whileCommand::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}

void setCommand::doCommand(vector<string> line, int i)
{
    if (line.size() == 3)                       //send set command
    {
        string stringSet = "set ";
        stringSet += Database::getInstance()->VarTable[line[0]] + " " + line[2] + "\r\n";
        cout << stringSet << endl;
        char* newStringSet = &stringSet[0];
        Client::getInstance()->Send(newStringSet);
    }
    else {cout << "Illegal command" << endl;}
}

void sleepCommand::doCommand(vector<string> line, int i)       //sleep
{
    if (line.size() == 2)
    {
        this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
        cout << "Waiting " << line[1] << " milliseconds" << endl;
    }
    else cout << "Illegal command" << endl;
}

