#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap();     //maybe should be in background
    Database::getInstance()->buildSymbolMap();      //maybe should be in background
    Parser::getInstance()->Lexing();

    // int i = 0;
    // while (Lexer::getInstance()->AllLinesSeparated.size() != 0)
    // {
    //     cout <<"\U0001F7E2 starting line "<<i<<"\n";
    //     Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[0], i);
    //     i++;
    //     cout <<"\U0001F534 finish line "<<i<<" -------------\n\n";
    // }

    for (size_t i = 0; i < Lexer::getInstance()->AllLines.size(); i++)
    {
        cout <<"\U0001F7E2 starting line "<<i<<"\n";
        i = Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i], i);
        
        cout <<"\U0001F534 finish line "<<i<<" -------------\n\n";
    }
    
    return 0;
}






