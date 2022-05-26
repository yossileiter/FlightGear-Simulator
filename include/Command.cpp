#include "Command.hpp"
#include "Database.hpp"     //this include can't work from header file
#include "parser.hpp"

template<typename K, typename V>
void PrintMap(unordered_map<K, V> const &m)
{
    for (auto const &pair: m)
    {
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
    }
    else {cout<<"open data server - Missing arguments"<<endl;}
}
int openServerCommand::get_i(int i)
{
    return i;
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
int connectCommand::get_i(int i)
{
    return i;
}

void varCommand::doCommand(vector<string> line, int i)
{
    if ((line[3] == "bind") && (line.size() == 5))  //bind a new var
    {   
        line[4].pop_back();
        line[4].erase(0,1);
        Database::getInstance()->VarTable[line[1]] = line[4];       //insert to var table
        cout << "'" << line[1] << "' bound successfully!" << endl;     
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        double valueForNewVar;
        string devicePath = Database::getInstance()->VarTable[line[3]];         //get device path from var table
        valueForNewVar = Database::getInstance()->SymbolTable[devicePath];      //get current value of the device
        Database::getInstance()->SymbolTable[line[1]] = valueForNewVar;         //insert the new var as key and current value as value
        cout << "'" << line[1] << "' Successfully inserted" << endl;
    }
    else {cout << "Illegal command" << endl;}
}
int varCommand::get_i(int i)
{
    return i;
}

void printCommand::doCommand(vector<string> line, int i)
{
    if (line[1][0] == '"')         //find "" in the line and remove it
    {
        line[1].erase(0,1);
        line[1].pop_back();
        cout << line[1] << endl;
    }
    else                            //print a variable
    {
        string path = Database::getInstance()->VarTable[line[1]]; 
        double value = Database::getInstance()->SymbolTable[path];
        cout << line[1] << ": " << value << endl;
    }
}
int printCommand::get_i(int i)
{
    return i;
}

void whileCommand::doCommand(vector<string> line, int i)
{
    cout<<"While loop {\n";

    int location = Lexer::getInstance()->FindElementLocation(Lexer::getInstance()->AllLinesSeparated, "}");
    vector<vector<string>> whileLines;

    for (size_t j = i+1; j < location; j++)                 //fill new vector with while lines
    {   
        whileLines.push_back(Lexer::getInstance()->AllLinesSeparated[j]);
    }
    loopLength = whileLines.size();                         //update the main i to skip the while lines                                

    if (CkeckElementInMap(Database::getInstance()->VarTable, line[1]) == 0)   //if var exist in var table
    {
        string devicePath = Database::getInstance()->VarTable[line[1]];         //get device path from var table
        double varValue = Database::getInstance()->SymbolTable[devicePath];            //get the variable value
        
        if (checkExpression(varValue, line[2], line[3]) == 1)       //check if the condition is met
        {
            for (size_t k = 0; k < whileLines.size(); k++)          //parse the while lines 
            {
                Parser::getInstance()->parsing(whileLines[k], i);
            }
            cout <<"}\nEnd while loop\n";
        }
        else (cout <<"The condition is not met\n}\n End while loop\n");
    }
    else cout << "Variable not found\n}\n End while loop\n";
}
int whileCommand::get_i(int i)                                  //increase the i by amount of while lines
{
    return i += loopLength;                                     
}

template<typename K, typename V, typename T>
bool whileCommand::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}
bool whileCommand::checkExpression(int x, string op, string yString)
{
    int y = stoi(yString);

    if      ((op == "==") && (x == y))  return true;
    else if ((op == "!=") && (x != y))  return true;
    else if ((op == "<")  && (x < y))   return true;
    else if ((op == ">")  && (x > y))   return true;
    else if ((op == "<=") && (x <= y))  return true;
    else if ((op == ">=") && (x >= y))  return true;
    else return false;
}

void setCommand::doCommand(vector<string> line, int i)
{
    double varValue;
    string stringSet = "set " + Database::getInstance()->VarTable[line[0]] + " ";

    if (line.size() == 3)                       //send set command
    {
        stringSet += line[2] + "\r\n";
        // cout << stringSet << endl;
        char* newStringSet = &stringSet[0];
        Client::getInstance()->Send(newStringSet);
        // return;
    }
    else if (line.size() > 3)
    {
        string tempStringSet;
        for (size_t j = 2; j < line.size(); j++)                                //for all elements in line (except the 2 first)
        {
            if (CkeckElementInMap(Database::getInstance()->SymbolTable, line[j]) == 0)     //for var h0
            {
                cout <<"in symbol" <<endl;
                // varValue = getVarValue(line[j]);                                        //get his value
                // stringSet2 += to_string(varValue);
                // cout<<"["<<line[j]<<" in. value: "<<varValue<<"] ";
                // cout<<"\n string set: "<<stringSet2<<endl;
                // return;
            }
            if (CkeckElementInMap(Database::getInstance()->VarTable, line[j]) == 0)     //if the var in var table
            {
                varValue = getVarValue(line[j]);                                        //get his value
                tempStringSet += to_string(varValue);
            }
            else
            {
                tempStringSet += line[j];
            }
        }

        string stringWithZero = "0";                        //avoid "-" in front of a line
        stringWithZero += tempStringSet;

        Calculator c;   
        double answer = c.calculate(stringWithZero);        //calculate the expression
        stringSet += to_string(answer)  += "\r\n";          
        char* newStringSet = &stringSet[0];                 
        Client::getInstance()->Send(newStringSet);          //send to client
    }
    else {cout << "Illegal command" << endl;}
}
template<typename K, typename V, typename T>
bool setCommand::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}
double setCommand::getVarValue(string var)
{
    string devicePath = Database::getInstance()->VarTable[var];         //get device path from var table
    double varValue = Database::getInstance()->SymbolTable[devicePath]; //get the variable value
    return varValue;
}
int setCommand::get_i(int i)
{
    return i;
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
int sleepCommand::get_i(int i)
{
    return i;
}
