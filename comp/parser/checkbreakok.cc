//#define XERR
#include "parser.ih"

SemVal Parser::checkBreakOK() const
{
    SemVal ret;

    if (not d_breakOK)
        Error::msg(Error::NO_BREAK);

    return ret;
}
