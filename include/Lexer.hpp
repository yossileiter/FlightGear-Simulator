#ifndef LEXER_H
#define LEXER_H

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
    vector<string> SplitLine(string s);

public:
    vector<string> AllLines;
    vector<vector<string>> AllLinesSeparated;

    static Lexer *getInstance();            // instantiating lexer
    void Lexing();                          // create a lexer and lex the file into vector of vectors
    void ReadInstructions(string FilePath); // read the instructions file and split to lines
};

#endif