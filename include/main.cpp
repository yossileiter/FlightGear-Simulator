#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap();     //maybe should be in background
    Database::getInstance()->buildSymbolMap();      //maybe should be in background
    Parser::getInstance()->Lexing();

    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i]);
    }
    // Database::getInstance()->PrintMap(Database::getInstance()->SymbolTable);

    return 0;
}


