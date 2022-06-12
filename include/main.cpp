#include "parser.hpp"

int main()
{
    LEXER->ReadTextFile("FlightInstructions.txt");

    Parser *parser = new Parser;
    for (size_t i = 0; i < LEXER->allTextLines.size(); i++)
    {
        i = parser->parsing(LEXER->allTextLines[i], i);
    }

    return 0;
}
