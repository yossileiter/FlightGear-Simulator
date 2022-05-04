#include "parser.cpp"

using namespace std;

int main()
{
    static Parser *parser = new Parser;
    parser->parse();
    return 0;
}
