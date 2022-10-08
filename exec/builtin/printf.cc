//#define XERR
#include "builtin.ih"

// prints the arguments of a printf call.
// 
// The arguments are: the number of arguments [2], and then the 
// remaining argument in the order in which they must be printed
//  ([3], [4], etc)

void Builtin::printf()
{
    d_reg = d_stack[2];

    insert(cout, 3, 3 + d_reg.value());
    xerr("returns: " << d_reg.value());
}
