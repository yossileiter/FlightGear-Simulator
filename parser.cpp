#include "parser.hpp"

Parser* Parser::instance = 0;
Parser* Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
}

void Parser::LetsLex() // create a lexer and lex the file into vector of vectors
{
    Command *ConnectCommand = new connectCommand();
    Command *OpenServerCommand = new openServerCommand();
    Command *VarCommand = new varCommand();

    CommandMap.insert({"connect", ConnectCommand});
    CommandMap.insert({"openDataServer", OpenServerCommand});
    CommandMap.insert({"var", VarCommand});

    Lexer *lexer = Lexer::getInstance();
    lexer->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        lexer->SplitLine(lexer->AllLines[i]);
        lexer->AllLinesSeparated.push_back(lexer->v);
    }
    parsing(lexer->AllLinesSeparated[0]);
}

void Parser::parsing(vector<string> v) // take a line and execute the suitable command
{
    Command* c = CommandMap.at(v[0]);
    c->doCommand(v);
}
