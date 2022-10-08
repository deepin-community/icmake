//#define XERR
#include "parser.ih"

SemVal Parser::breakStmnt() const
{
    SemVal ret{ checkBreakOK() };

    ret.breakStmnt();

    return ret;
}
