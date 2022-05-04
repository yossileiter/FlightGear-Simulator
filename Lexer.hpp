#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

class Lexer
{
public:
    
    Lexer(){}
    void ReadInstructions(string FilePath);
    void SplitLine(string s);
    void PrintVector(vector<string> v);
    void printing();
};