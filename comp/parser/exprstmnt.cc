#define XERR
#include "parser.ih"

SemVal Parser::exprStmnt(SemVal &expr) const
{
    return expr.type() & e_printMask ? pushPrint(expr) : expr.exprStmnt();
}
