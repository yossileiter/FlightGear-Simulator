#include "parser.hpp"

using namespace std;

int main()
{
    // unordered_map<string, string> CommandsMap;
    Parser *parser = Parser::getInstance();
    parser->LetsLex();
    return 0;
}
