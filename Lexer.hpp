#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Lexer
{
private:
    Lexer(){}
    static Lexer* instance;

public:
    vector<string> AllLines, v;
    vector<vector<string>> AllLinesSeparated;

    static Lexer *getInstance();
    void ReadInstructions(string FilePath); //read the instructions file and split to lines
    void SplitLine(string s);               //split a line into words
    void PrintVector(vector<string> v);     //print a vector
};