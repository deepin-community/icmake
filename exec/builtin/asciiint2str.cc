//#define XERR
#include "builtin.ih"

// ascii(25) returns the string "A": the value is converted to an ascii
// character in a returned String
    
void Builtin::asciiInt2str()
{
    d_reg = string{ as<char>( d_stack.top().value() ) };
}
