#include "parser.hpp"

using namespace std;

int main()
{
    Parser *parser = Parser::getInstance();
    parser->LetsLex();
    return 1;
}
