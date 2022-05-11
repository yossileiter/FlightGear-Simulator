#include "parser.hpp"
#include "Lexer.hpp"
#include "Command.hpp"

Parser* Parser::instance = 0;
Parser* Parser::getInstance()
{
	if(!instance) instance = new Parser();
	return instance;	
}

void Parser::LetsLex() // create a lexer and lex the file into vector of vectors
{
    Lexer *lexer = Lexer::getInstance();
    lexer->ReadInstructions("FlightInstructions.txt");
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        lexer->SplitLine(lexer->AllLines[i]);
        lexer->AllLinesSeparated.push_back(lexer->v);
    }
    parsing(lexer->AllLinesSeparated[0]);
    delete lexer;
}

void Parser::parsing(vector<string> v) // take a line and execute the suitable command
{
    string command = v[0];
    if (1>2){}
    // if (VarTable.find(command) == VarTable.end())
    // {
    //     setCommand *SetCommand = new setCommand();
    //     SetCommand->doCommand(v);
    // }
    else if (command == "connect")
    {

        connectCommand *ConnectCommand = new connectCommand();
        ConnectCommand->doCommand(v);
    }
    else if (command == "openDataServer")
    {
        openServerCommand *OpenServerCommand = new openServerCommand();
        OpenServerCommand->doCommand(v);
    }
    else if (command == "var")
    {
        varCommand *VarCommand = new varCommand();
        VarCommand->doCommand(v);
    }
    else
        cout << "Illegal command" << endl;
}
