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

public:
    vector<string> AllLines, v;
    vector<vector<string>> AllLinesSeparated;

    static Lexer *getInstance();            // instantiating lexer
    void ReadInstructions(string FilePath); // read the instructions file and split to lines
    void SplitLine(string s);               // split a line into words
    bool FindIfElementExist(vector<string> v, string element);
    int FindElementLocation(vector<vector<string>> v, string element);
};

#endif