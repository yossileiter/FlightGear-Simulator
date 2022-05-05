#include "parser.hpp"
#include "Lexer.hpp"
#include "Command.hpp"


void Parser::LetsLex() //create a lexer and lex the file into vector of vectors
{
    static Lexer *lexer = new Lexer;
    lexer->ReadInstructions("FlightInstructions.txt"); 
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        lexer->SplitLine(lexer->AllLines[i]);
        lexer->AllLinesSeparated.push_back(lexer->v);
    }
    parsing(lexer->AllLinesSeparated[0]);
    delete lexer;
}

void Parser::parsing(vector<string> vec) //take a line and execute the suitable command
{
    string command = vec[0];
    if (command == "connect")
    {
        
        connectCommand *ConnectCommand = new connectCommand();
        ConnectCommand->doCommand(vec);
    }
    else if (command == "openDataServer")
    {
        openServerCommand *OpenServerCommand = new openServerCommand();
        OpenServerCommand->doCommand(vec);    
        
    }
    else    cout<<"Illegal command"<<endl;
}

