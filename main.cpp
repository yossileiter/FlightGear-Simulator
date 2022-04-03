#include "parser.cpp"

using namespace std;

int main()
{
    static Lexer *lexer = new Lexer;
    lexer->lex(s); 
    lexer->PrintVector(v);
    static Parser *parser = new Parser;
    parser->parse(v);
    // parse(v);

    return 0;
}