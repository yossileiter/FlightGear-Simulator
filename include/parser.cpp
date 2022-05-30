#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
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
    else if (Database::getInstance()->VarTable.find(line[0]) == Database::getInstance()->VarTable.end()) //if the line[0] is a command
    {
        Database::getInstance()->CommandMap[line[0]]->doCommand(line, i);
        return Database::getInstance()->CommandMap[line[0]]->get_i(i);
    }
    else if (CkeckIfElementInMap(Database::getInstance()->CommandMap, line[0]) == 0)          //if line[0] is a var
    {
        Database::getInstance()->CommandMap["set"]->doCommand(line, i);  
        return Database::getInstance()->CommandMap["set"]->get_i(i);
    }
    return 0;
}
