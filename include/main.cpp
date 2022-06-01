#include "parser.hpp"

int main()
{
    LEXER->ReadInstructions("FlightInstructions.txt");
    LEXER->Lexing();

    for (size_t i = 0; i < LEXER->AllLinesSeparated.size(); i++)
    {
        i = PARSER->parsing(LEXER->AllLinesSeparated[i], i);
    }

    return 0;
}
