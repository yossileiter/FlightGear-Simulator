#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *PARSER  //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

template<typename K, typename V, typename T>
bool Parser::CkeckIfElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element) == 0) return 0;
    else return 1;
}


int Parser::parsing(vector<string> line, size_t i) // take a line and execute the suitable command
{   
    if (line[0]=="}")
    {
        return i;
    }
    else if (CkeckIfElementInMap(DATABASE->CommandMap, line[0]) == 1) //if the line[0] is a command
    {
        DATABASE->CommandMap[line[0]]->doCommand(line, i);
        return DATABASE->CommandMap[line[0]]->get_i(i);
    }
    else if (DATABASE->VarTable.find(line[0]) != DATABASE->VarTable.end())          //if line[0] is a var
    {
        DATABASE->CommandMap[line[1]]->doCommand(line, i);  
        return DATABASE->CommandMap[line[1]]->get_i(i);
    }
    return 0;
}
