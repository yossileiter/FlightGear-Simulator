#include "Lexer.hpp"

Lexer *Lexer::instance = 0;

Lexer *Lexer::getInstance()
{
	if(!instance) instance = new Lexer();
	return instance;
}

void Lexer::ReadTextFile(string FilePath) // read the instructions file and split to lines
{
    fstream newfile;
    newfile.open(FilePath, ios::in);
    if (newfile.is_open())
    {
        vector<string> AllLines;
        string line;
        while (getline(newfile, line))
        {
            while (line[0] == ' ') line.erase(0, 1);    // remove indentation
            AllLines.push_back(line);                   // split all text to lines
        }
        newfile.close();

        for (int i = 0; i < AllLines.size(); i++)
        {
            LEXER->allTextLines.push_back(splitLineIntoWords(AllLines[i])); // split every line to words
        }
    }
}

vector<string> Lexer::splitLineIntoWords(string s)
{
    vector<string> v;
    string temp;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            v.push_back(temp);
            temp = "";
        }
        else { temp.push_back(s[i]); }
    }
    v.push_back(temp);
    return v;
}
