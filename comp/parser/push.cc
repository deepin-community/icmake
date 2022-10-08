//#define XERR
#include "parser.ih"

void Parser::push()
{
    d_symtab.push();
    SemVal::pushDead();
}
