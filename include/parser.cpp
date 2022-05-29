#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

vector <string> Parser::SplitLine(string s)
{
    vector <string> v;
    string temp = "";
    for(int i = 0 ; i < s.length(); ++i)
    {
        if(s[i]==' ') v.push_back(temp), temp = "";
        else { temp.push_back(s[i]); }		
    }
    v.push_back(temp);
    return v;
}

template<typename K, typename V, typename T>
bool Parser::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element) == 0) return 0;
    else return 1;
}

void Parser::Lexing() // create a lexer and lex the file into vector of vectors
{
    Lexer::getInstance()->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Lexer::getInstance()->AllLinesSeparated.push_back(SplitLine(Lexer::getInstance()->AllLines[i]));
    }
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
    else if (CkeckElementInMap(Database::getInstance()->CommandMap, line[0]) == 0)          //if line[0] is a var
    {
        Database::getInstance()->CommandMap["set"]->doCommand(line, i);  
        return Database::getInstance()->CommandMap["set"]->get_i(i);
    }
    return 0;
}
