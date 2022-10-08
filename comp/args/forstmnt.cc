#define XERR
#include "args.ih"

// '*this' is the init section

SemVal Args::forStmnt(SemVal &cond, Args &inc, SemVal &stmnt)
{
    SemVal incSv = inc.catExpressions(inc.size());

    return catExpressions(size()).forStmnt(cond, incSv, stmnt);
}
