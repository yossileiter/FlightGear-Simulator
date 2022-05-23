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

void Parser::parsing(vector<string> line, size_t i) // take a line and execute the suitable command
{
    auto it = Database::getInstance()->VarTable.find(line[0]);
    if (it == Database::getInstance()->VarTable.end())
    {
        Database::getInstance()->CommandMap[line[0]]->doCommand(line);
    }
    else if (CkeckElementInMap(Database::getInstance()->CommandMap, line[0]) == 0)
    {
        Database::getInstance()->CommandMap["set"]->doCommand(line);     
    }
    else
    {
        int location = Lexer::getInstance()->FindElementLocation(Lexer::getInstance()->AllLinesSeparated, "}");
        if (location != 0) cout<<"location: "<<location<<endl;
        else cout<<"not found\n";
    }
}

void Parser::PrintVector(vector<string> v) //print a vector
    {
        for(size_t i=0;i<v.size();++i)
            // cout<<"Line "<<i<<": "<<v[i]<<endl;
            cout<<v[i]<<endl;
        cout<<"\n";
    }
