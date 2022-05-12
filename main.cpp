#include "parser.hpp"

int main()
{
    Parser *parser = Parser::getInstance();
    Lexer *lexer = Lexer::getInstance();

    parser->BuildCommandsMap();
    parser->Lexing();

    for (int i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        parser->parsing(Lexer::getInstance()->AllLinesSeparated[i]);
    }

    return 2;
}


