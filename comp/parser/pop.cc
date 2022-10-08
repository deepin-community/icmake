//#define XERR
#include "parser.ih"

void Parser::pop()
{
    d_symtab.pop();
    SemVal::popDead();
}
