//#define XERR
#include "parser.ih"

SemVal Parser::pushPrint(SemVal &expr) const
{
    return expr.type() & e_printMask ?
                function(
                    expr.type() == e_printf ? "printf" : "fprintf",
                    Args{ expr.printfArgs() }
                ).exprStmnt()
            :
                move(expr);
}
