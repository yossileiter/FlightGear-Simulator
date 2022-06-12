#include "Command.hpp"
#include "Database.hpp"
#include "parser.hpp"

double Command::getVarValue(string var)
{
    string devicePath = DATABASE->VarTable[var];         //get device path from var table
    double varValue = DATABASE->SymbolTable[devicePath]; //get the variable value
    return varValue;
}

template<typename K, typename V, typename T>
bool Command::CheckIfElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element)) return 0;
    else return 1;
}

void openServerCommand::doCommand(const vector<string> &line, int i)
{
    if (line.size() == 2)
    {
        int port = stoi(line[1]);
        const char *ip = "127.0.0.1";
        Server::getInstance()->Connect(port, ip);
    }
    else {cout<<"open data server - Missing arguments"<<endl;}
}

void connectCommand::doCommand(const vector<string> &line, int i)
{
    if (line.size() == 3)
    {
        const char *ip = line[1].c_str();
        int port = stoi(line[2]);
        Client::getInstance()->Connect(port, ip);
    }
    else {cout<<"connect - Missing arguments"<<endl;}
}

void varCommand::doCommand(const vector<string> &line, int i)
{   
    if ((line[3] == "bind") && (line.size() == 5))  //bind a new var
    {   
        string path = line[4];
        path.pop_back();
        path.erase(0,1);
        DATABASE->VarTable[line[1]] = path;       //insert to var table
        cout << "'" << line[1] << "' bound successfully!" << endl;  
    }   
    else if (line.size() == 4)                     //insert an assignment var into the symbol table
    {
        DATABASE->SymbolTable[line[1]] = getVarValue(line[3]);         //insert the new var as key and current value as value
        cout << "'" << line[1] << "' Successfully inserted" << endl;
    }
    else {cout << "Illegal command" << endl;}
}

void printCommand::doCommand(const vector<string> &line, int i)
{
    if (line[1][0] == '"')         //print text
    {
        string textToPrint = line[1];
        textToPrint.erase(0,1);
        textToPrint.pop_back();
        cout << textToPrint << endl;
    }
    else                            //print a variable
    {
        cout << line[1] << ": " << getVarValue(line[1]) << endl;
    }
}

void whileCommand::doCommand(const vector<string> &line, int i)
{
    cout<<"While loop {\n";
    vector<vector<string>> whileLines;

    int bracketLocation = FindElementLocation(LEXER->allTextLines, "}", i);  

    for (size_t j = i+1; j < bracketLocation; j++)                 //fill new vector with while lines
    {   
        whileLines.push_back(LEXER->allTextLines[j]);
    }
    loopLength = whileLines.size();                         //update the main i to skip the while lines                                

    if (CheckIfElementInMap(DATABASE->VarTable, line[1]) == 0)   //if line[1] is in var table
    {        
        while (checkExpression(getVarValue(line[1]), line[2], line[3]) == 1)       //check if the condition is met
        {
            Parser *parser = new Parser;
            for (size_t k = 0; k < whileLines.size(); k++)          //parse the while lines 
            {
                parser->parsing(whileLines[k], i);
            }
            delete parser;
            cout << endl;
        }
        cout <<"}\nEnd while loop\n";
    }
    else cout << "Variable not found\n}\n End while loop\n";
}

bool whileCommand::FindIfElementInVector(vector<string> v, string element)
{    
    vector<string>::iterator it = find(v.begin(), v.end(), element.c_str());
    if (it != v.end()) return 1;
    else return 0;
}

int whileCommand::FindElementLocation(vector<vector<string>> v, string element, int i)
{
    for (size_t row = i; row < LEXER->allTextLines.size(); row++)
    {
        if (FindIfElementInVector(LEXER->allTextLines[row], element)) return row;
    }
    return 0;
}


bool whileCommand::checkExpression(double x, string op, string yString)
{
    double y = stod(yString);

    if      ((op == "==") && (x == y))  return true;
    else if ((op == "!=") && (x != y))  return true;
    else if ((op == "<")  && (x < y))   return true;
    else if ((op == ">")  && (x > y))   return true;
    else if ((op == "<=") && (x <= y))  return true;
    else if ((op == ">=") && (x >= y))  return true;
    else return false;
}

void setCommand::doCommand(const vector<string> &line, int i)
{
    double varValue;
    string stringSet = "set " + DATABASE->VarTable[line[0]] + " ";

    if (line.size() == 3)                       //send set command
    {
        stringSet += line[2] + "\r\n";
        char* stringSetChar = &stringSet[0];
        Client::getInstance()->Send(stringSetChar);
    }
    else if (line.size() > 3)
    {
        string mathematicalExpression;
        for (size_t j = 2; j < line.size(); j++)                                //for all elements in line (except the first 2)
        {
            if (CheckIfElementInMap(DATABASE->SymbolTable, line[j]) == 0)       //for var h0
            {           
                varValue = DATABASE->SymbolTable[line[j]];                      
                mathematicalExpression += to_string(varValue);
            }
            else if (CheckIfElementInMap(DATABASE->VarTable, line[j]) == 0)     //if the var in var table
            {
                varValue = getVarValue(line[j]);                                
                mathematicalExpression += to_string(varValue);
            }
            else                                                                //for other signs
            {
                mathematicalExpression += line[j];
            }
        }

        Calculator c;   
        double result = c.calculate(mathematicalExpression);        //calculate the expression
        
        stringSet += to_string(result)  += "\r\n";          
        char* stringSetChar = &stringSet[0];                 
        Client::getInstance()->Send(stringSetChar);          //send to client
    }
    else {cout << "Illegal command" << endl;}
}

void sleepCommand::doCommand(const vector<string> &line, int i)       //sleep
{
    if (line.size() == 2)
    {
        cout << "Waiting " << line[1] << " Milliseconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
    }
    else cout << "Illegal command" << endl;
}

void doNothingCommand::doCommand(const vector<string> &line, int i)
{
    cout << "Unknown command" << endl; 
}
