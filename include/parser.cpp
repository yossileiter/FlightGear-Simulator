#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

template<typename K, typename V, typename T>
bool Parser::CkeckElementInMap(unordered_map<K,V> const &map, T element)
{
    if (map.count(element) == 0) return 0;
    else return 1;
}

void Parser::BuildCommandsMap() //create commands objects and insert to hash table
{
    
}

void Parser::Lexing() // create a lexer and lex the file into vector of vectors
{
    Lexer::getInstance()->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Lexer::getInstance()->SplitLine(Lexer::getInstance()->AllLines[i]);
        Lexer::getInstance()->AllLinesSeparated.push_back(Lexer::getInstance()->v);
        Lexer::getInstance()->v.clear();
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
}

void Parser::PrintVector(vector<string> v) //print a vector
    {
        for(size_t i=0;i<v.size();++i)
            cout<<v[i]<<endl;
        cout<<"\n";
    }
