//#define XERR
#include "args.ih"

// the current Args object contains the if stmnt's initialization list as its
// size() - 1 initial elements. Its final element is the actual condition.
// The initial size() - 1 elements are concatenated, resulting in a SemVal,
// which then calls SemVal::ifStmnt, receiving its final element and trueStmnt
// and falseStmnt as its arguments.

SemVal Args::ifStmnt(SemVal &trueStmnt, SemVal &falseStmnt)
{
                                // push the initialization code and
                                // complete the ifstmnt 
    return catExpressions(size() - 1).ifStmnt(back(), trueStmnt, falseStmnt);
}
