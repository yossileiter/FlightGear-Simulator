#ifndef LEXER_H
#define LEXER_H

#define LEXER Lexer::getInstance()

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Lexer
{
private:
    Lexer() {}
    static Lexer *instance;
    vector<string> splitLineIntoWords(string s);

public:
    
    vector<vector<string>> allTextLines;
    static Lexer *getInstance();            // instantiating lexer
    void ReadTextFile(string FilePath);     // read the instructions file and split to lines
};

#endif