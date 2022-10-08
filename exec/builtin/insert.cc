//#define XERR
#include "builtin.ih"

// begin is the stack location of the 1st argument to process, 
// end is the stack location just beyond the last arg. to process

void Builtin::insert(ostream &out, size_t begin, size_t end) const
{
    xerr("");

    auto const &arg1 = d_stack[begin];
    
    if (not arg1.isString() || not (s_percent << arg1.str()) )
        insertDirect(out, begin, end);
    else
        insertReplace(out, arg1.str(), begin);
}
