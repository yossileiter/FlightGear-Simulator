#include "Lexer.hpp"

Lexer* Lexer::instance = 0;
Lexer* Lexer::getInstance()
{
	if (!instance) instance = new Lexer;
	return instance;
}

void Lexer::ReadInstructions(string FilePath) //read the instructions file and split to lines
{
    fstream newfile;
    newfile.open(FilePath,ios::in); 
    if (newfile.is_open())
    { 
        string line;
        while(getline(newfile, line)) AllLines.push_back(line); //read data from file object and put it into string.
        newfile.close(); 
    }
}

