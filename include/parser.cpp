#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

void Parser::BuildCommandsMap() //create commands objects and insert to hash table
{
    // Command *ConnectCommand = new connectCommand();
    // Command *OpenServerCommand = new openServerCommand();
    // Command *VarCommand = new varCommand();

    // Database::getInstance()->CommandMap["connect"] = ConnectCommand;
    // Database::getInstance()->CommandMap["openDataServer"] = OpenServerCommand;
    // Database::getInstance()->CommandMap["var"] = VarCommand;
}

void Parser::Lexing() // create a lexer and lex the file into vector of vectors
{
    Lexer::getInstance()->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Lexer::getInstance()->SplitLine(Lexer::getInstance()->AllLines[i]);
        Lexer::getInstance()->AllLinesSeparated.push_back(Lexer::getInstance()->v);
    }
}

void Parser::parsing(vector<string> line) // take a line and execute the suitable command
{
    //to do: check if v[0] i legal
    // Command* c = Database::getInstance()->CommandMap.at("var");
    Command* c = Database::getInstance()->CommandMap[line[0]];
    c->doCommand(line);
}
