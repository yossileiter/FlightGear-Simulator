#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

void Parser::BuildCommandsMap() //create commands objects and insert to hash table
{
    Command *ConnectCommand = new connectCommand();
    Command *OpenServerCommand = new openServerCommand();
    Command *VarCommand = new varCommand();

    CommandMap["connect"] = ConnectCommand;
    CommandMap["openDataServer"] = OpenServerCommand;
    CommandMap["var"] = VarCommand;
}

void Parser::Lexing() // create a lexer and lex the file into vector of vectors
{
    Lexer *lexer = Lexer::getInstance();
    lexer->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        lexer->SplitLine(lexer->AllLines[i]);
        lexer->AllLinesSeparated.push_back(lexer->v);
    }
}

void Parser::parsing(vector<string> line) // take a line and execute the suitable command
{
    //to do: check if v[0] i legal
    Command* c = CommandMap.at(line[0]);
    c->doCommand(line);
}
