//#define XERR
#include "scanner.ih"

int Scanner::token(int token, size_t expr)
{
    d_expr = expr;
    return token;
}
