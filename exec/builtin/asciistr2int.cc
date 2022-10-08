#define XERR
#include "builtin.ih"

// ascii("Abc") returns the ascii value of the first char in the string as int
// value (in the example: 'A' -> 65). For an empty string 0 is returned
    
void Builtin::asciiStr2int()
{
    xerr("");
    string const &str = d_stack.top().str();

    d_reg = as<int>( str.empty() ? '\0' : str[0] );
    xerr("done");
}

