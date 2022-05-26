#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap();     //maybe should be in background
    Database::getInstance()->buildSymbolMap();      //maybe should be in background
    Parser::getInstance()->Lexing();
    // Calculator c;
    // cout<<c.calculate("2.0000000/70")<<endl;

    for (size_t i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        i = Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i], i);    
    }
    
    return 0;
}






