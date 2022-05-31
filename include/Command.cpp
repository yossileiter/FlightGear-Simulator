#include "Command.hpp"
#include "Database.hpp"     //this include can't work from header file
#include "parser.hpp"

double Command::getVarValue(string var)
{
    string devicePath = Database::getInstance()->VarTable[var];         //get device path from var table
    double varValue = Database::getInstance()->SymbolTable[devicePath]; //get the variable value
    return varValue;
}

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
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        Database::getInstance()->SymbolTable[line[1]] = getVarValue(line[3]);         //insert the new var as key and current value as value
        cout << "'" << line[1] << "' Successfully inserted" << endl;
    }
    else {cout << "Illegal command" << endl;}
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
        cout << line[1] << ": " << getVarValue(line[1]) << endl;
    }
}

void whileCommand::doCommand(vector<string> line, int i)
{
    cout<<"While loop {\n";
    vector<vector<string>> whileLines;

    int location = FindElementLocation(Lexer::getInstance()->AllLinesSeparated, "}", i);

    for (size_t j = i+1; j < location; j++)                 //fill new vector with while lines
    {   
        whileLines.push_back(Lexer::getInstance()->AllLinesSeparated[j]);
    }
    loopLength = whileLines.size();                         //update the main i to skip the while lines                                

    if (CkeckElementInMap(Database::getInstance()->VarTable, line[1]) == 0)   //if var exist in var table
    {        
        while (checkExpression(getVarValue(line[1]), line[2], line[3]) == 1)       //check if the condition is met
        {
            for (size_t k = 0; k < whileLines.size(); k++)          //parse the while lines 
            {
                Parser::getInstance()->parsing(whileLines[k], i);
            }
            cout << endl;
        }
        cout <<"}\nEnd while loop\n";
    }
    else cout << "Variable not found\n}\n End while loop\n";
}

bool whileCommand::FindIfElementExist(vector<string> v, string element)
{    
    vector<string>::iterator it = find(v.begin(), v.end(), element.c_str());
    if (it != v.end()) return 1;
    else return 0;
}

int whileCommand::FindElementLocation(vector<vector<string>> v, string element, int i)
{
    for (size_t rows = i; rows < Lexer::getInstance()->AllLinesSeparated.size(); rows++)
    {
        if (FindIfElementExist(Lexer::getInstance()->AllLinesSeparated[rows], element)) return rows;
    }
    return 0;
}


template<typename K, typename V, typename T>
bool whileCommand::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}
bool whileCommand::checkExpression(double x, string op, string yString)
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
        char* newStringSet = &stringSet[0];
        Client::getInstance()->Send(newStringSet);
        cout << newStringSet <<endl;
    }
    else if (line.size() > 3)
    {
        string tempStringSet;
        for (size_t j = 2; j < line.size(); j++)                                //for all elements in line (except the 2 first)
        {
            if (CkeckElementInMap(Database::getInstance()->SymbolTable, line[j]) == 0)     //for var h0
            {
                varValue = Database::getInstance()->SymbolTable[line[j]]; 
                tempStringSet += to_string(varValue);
            }
            else if (CkeckElementInMap(Database::getInstance()->VarTable, line[j]) == 0)     //if the var in var table
            {
                varValue = getVarValue(line[j]);                                        //get his value
                tempStringSet += to_string(varValue);
            }
            else
            {
                tempStringSet += line[j];
            }
        }

        Calculator c;   
        double answer = c.calculate(tempStringSet);        //calculate the expression
        
        stringSet += to_string(answer)  += "\r\n";          
        char* stringSetToChar = &stringSet[0];                 
        Client::getInstance()->Send(stringSetToChar);          //send to client
        cout << stringSetToChar <<endl;     //delete
    }
    else {cout << "Illegal command" << endl;}
}
template<typename K, typename V, typename T>
bool setCommand::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}

void sleepCommand::doCommand(vector<string> line, int i)       //sleep
{
    if (line.size() == 2)
    {
        cout << "Waiting " << line[1] << " Milliseconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
    }
    else cout << "Illegal command" << endl;
}
