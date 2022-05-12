#include "parser.hpp"

int main()
{
    // Parser *parser = Parser::getInstance();
    // Lexer *lexer = Lexer::getInstance();

    Database::getInstance()->buildmap();
    Parser::getInstance()->Lexing();

    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i]);
    }



    return 0;
}


