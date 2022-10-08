#define XERR
#include "args.ih"

Args &Args::add(SemVal &semVal)
{
    push_back(move(semVal));
    return *this;
}
