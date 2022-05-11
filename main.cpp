#include "parser.hpp"

int main()
{
    Parser *parser = Parser::getInstance();
    Lexer *lexer = Lexer::getInstance();

    parser->BuildCommandsMap();
    parser->Lexing();
    
    for (int i = 0; i < lexer->AllLines.size(); i++)
    {
        parser->parsing(lexer->AllLinesSeparated[i]);
    }

    return 0;
}
