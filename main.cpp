#include "parser.hpp"

using namespace std;

int main()
{
    // unordered_map<string, string> CommandsMap;
    static Parser *parser = new Parser;
    parser->LetsLex();
    return 0;
}
