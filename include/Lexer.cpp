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

void Lexer::Lexing() // create a lexer and lex the file into vector of vectors
{
    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Lexer::getInstance()->AllLinesSeparated.push_back(SplitLine(Lexer::getInstance()->AllLines[i]));
    }
}

vector <string> Lexer::SplitLine(string s)
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
