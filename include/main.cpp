#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap(); // maybe should be in background
    Lexer::getInstance()->ReadInstructions("FlightInstructions.txt");
    Lexer::getInstance()->Lexing();

    for (size_t i = 0; i < Lexer::getInstance()->AllLinesSeparated.size(); i++)
    {
        i = Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i], i);
    }
    
    return 0;
}
