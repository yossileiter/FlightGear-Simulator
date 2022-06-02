#include "parser.hpp"

int main()
{
    LEXER->ReadTextFile("FlightInstructions.txt");

    for (size_t i = 0; i < LEXER->allTextLines.size(); i++)
    {
        i = PARSER->parsing(LEXER->allTextLines[i], i);
        cout <<"################################"<<endl<<"i: "<<i<<endl;
    }

    return 0;
}
