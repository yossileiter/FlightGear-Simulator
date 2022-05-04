#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Lexer
{
public:
    vector<string> AllLines, v;
    vector<vector<string>> AllLinesSeparated;
    Lexer(){}
    void ReadInstructions(string FilePath);
    void SplitLine(string s);
    void PrintVector(vector<string> v);
};