#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap();     //maybe should be in background
    Parser::getInstance()->Lexing();

    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i]);
    }
    

    return 0;
}


