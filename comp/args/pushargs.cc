//#define XERR
#include "args.ih"

uint8_t Args::pushArgs(SemVal &ret)
{
                              // push all arguments in reversed order
    for (auto begin = rbegin(), end = rend(); begin != end; ++begin)
    {
        begin->push();
        ret << *begin;
    }

    return size();
}
