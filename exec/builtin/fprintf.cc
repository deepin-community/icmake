//#define XERR
#include "builtin.ih"

// prints the arguments of an fprintf call.
// 
// The arguments are: the number of arguments ([2]), a filename ([3]), and
// then the remaining arguments in the order in which they must be printed 
// ([4], [5], ...) 

void Builtin::fprintf()
{
    d_reg = d_stack[2];

    ofstream out = Exception::factory<ofstream>( 
                                    d_stack[3].str(), 
                                    ios::in | ios::ate, ios::out);

                                    // first arg = [2] (#args)
    insert(out, 4, 3 + d_reg.value());
}
