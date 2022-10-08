//#define XERR
#include "parser.ih"

SemVal Parser::continueStmnt() const
{
    SemVal ret{ checkBreakOK() };

    ret.continueStmnt();

    return ret;
}
