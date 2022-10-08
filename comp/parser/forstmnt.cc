#define XERR
#include "parser.ih"

SemVal Parser::forStmnt(Args &&init, SemVal &cond, Args &&inc, SemVal &stmnt)
{
    SemVal ret = init.forStmnt(cond, inc, stmnt);
    pop();
    --d_breakOK;
    return ret;
}
