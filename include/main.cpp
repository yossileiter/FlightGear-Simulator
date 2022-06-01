#include "parser.hpp"

int main()
{
    LEXER->ReadTextFile("FlightInstructions.txt");

    for (size_t i = 0; i < LEXER->flightPlan.size(); i++)
    {
        i = PARSER->parsing(LEXER->flightPlan[i], i);
    }

    return 0;
}
