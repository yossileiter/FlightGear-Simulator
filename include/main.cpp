#include "parser.hpp"

int main()
{
    Database::getInstance()->buildCommandMap();     //maybe should be in background
    Parser::getInstance()->Lexing();
    // system("fgfs --telnet=socket,in,10,127.0.0.1,5402,tcp --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small");
    for (size_t i = 0; i < Lexer::getInstance()->AllLinesSeparated.size(); i++)
    {
        i = Parser::getInstance()->parsing(Lexer::getInstance()->AllLinesSeparated[i], i);    
    }

    return 0;
}


