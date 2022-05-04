#include "parser.cpp"

using namespace std;

int main()
{
    static Lexer *lexer = new Lexer;
    lexer->ReadInstructions("FlightInstructions.txt"); 
    for (int i = 0; i < AllLines.size(); i++)
    {
        lexer->SplitLine(AllLines[i]);
        AllLinesSeparated.push_back(v);
    }
    delete lexer;
    
    static Parser *parser = new Parser;
    for (size_t i = 0; i < AllLinesSeparated.size(); i++)
    {
        parser->parse(AllLinesSeparated[i]);
    }
    delete parser;
    return 0;
}
