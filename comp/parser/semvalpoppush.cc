//#define XERR
#include "parser.ih"

// static
void Parser::semValPopPush()
{
    SemVal::popDead();
    SemVal::pushDead();
}
