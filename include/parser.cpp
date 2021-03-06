#include "parser.hpp"
#include "Database.hpp"


template<typename K, typename V, typename T>
bool Parser::CheckIfElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element) == 0) return 0;
    else return 1;
}


int Parser::parsing(const vector<string> &line, size_t i)       // take a line and execute the suitable command
{   
    string command;

    if (CheckIfElementInMap(DATABASE->CommandMap, line[0]))                 // line[0] is a command
    {
        command = line[0];
    }
    else if (DATABASE->VarTable.find(line[0]) != DATABASE->VarTable.end())  // line[0] is a var
    {
        command = line[1];
    }
    else { command = "unknownCommand"; }                                    // unknown command 

    DATABASE->CommandMap[command]->doCommand(line, i);  
    return DATABASE->CommandMap[command]->get_i(i);
}
