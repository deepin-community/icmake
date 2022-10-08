//#define XERR
#include "builtin.ih"

// prints the formatted (%\d+) arguments into a string
// 
// The arguments are: the number of arguments [2], and then the 
// remaining arguments (the format string at [3]) in the order in which they
// are referred to by %\d. (%1 = [3 + 1], etc)
// 
// Since this is a formatted string print, insertReplace instead of insert is
// called directly 

void Builtin::strFormat()
{
    ostringstream out;
    insertReplace(out, d_stack[3].str(), 3);

    d_reg = out.str();
}
