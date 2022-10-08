//#define XERR
#include "parser.ih"

// 'cond' contains the initialization list and the actual condition as
//  its final element: see also Args::ifStmnt 

SemVal Parser::ifStmnt(Args &cond, SemVal &trueStmnt, SemVal &falseStmnt)
{
    SemVal ret = cond.ifStmnt(trueStmnt, falseStmnt);
    pop();
    return ret;
}
