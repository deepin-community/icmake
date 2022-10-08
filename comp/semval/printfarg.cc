//#define XERR
#include "semval.ih"

SemVal SemVal::printfArg(SemVal &arg)
{
    d_printfArgs.push_back(move(arg));
    return move(*this);
}
