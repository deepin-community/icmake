//#define XERR
#include "builtin.ih"

// the 1st arg is begin, beyond the last is at end

void Builtin::insertDirect(ostream &out, size_t begin, size_t end) const
{
    for (; begin != end; ++begin)
    {
        xerr(begin << ": `" << d_stack[begin] << "' (begin: " << begin << ")'");
        out << d_stack[begin];
    }
}
