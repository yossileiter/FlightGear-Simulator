#include "Lexer.hpp"

Lexer *Lexer::instance = 0;
Lexer *LEXER
{
    if (!instance)
        instance = new Lexer;
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
            AllLines.push_back(line); // read data from file object and put it into string.
        newfile.close();

        for (int i = 0; i < AllLines.size(); i++)
        {
            LEXER->allTextLines.push_back(splitLineIntoWords(AllLines[i]));
        }
    }
}

vector<string> Lexer::splitLineIntoWords(string s)
{
    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
            v.push_back(temp), temp = "";
        else
        {
            temp.push_back(s[i]);
        }
    }
    v.push_back(temp);
    return v;
}
