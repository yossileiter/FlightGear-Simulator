#include "parser.hpp"

Parser *Parser::instance = 0;

Parser *Parser::getInstance()   //create a singleton
{
	if(!instance) instance = new Parser();
	return instance;	
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

void Parser::parsing(vector<string> line) // take a line and execute the suitable command
{
    //to do: check if v[0] i legal
    Database::getInstance()->CommandMap[line[0]]->doCommand(line);
}

void Parser::PrintVector(vector<string> v) //print a vector
    {
        for(int i=0;i<v.size();++i)
            // cout<<"Line "<<i<<": "<<v[i]<<endl;
            cout<<v[i]<<endl;
        cout<<"\n";
    }