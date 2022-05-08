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
    void ReadInstructions(string FilePath); //read the instructions file and split to lines
    void SplitLine(string s);               //split a line into words
    void PrintVector(vector<string> v);     //print a vector
};