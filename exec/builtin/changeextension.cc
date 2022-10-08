//#define XERR
#include "builtin.ih"

// the stack's top contains the filename, the element before that
// the new extension

void Builtin::changeExtension()
{
    filesystem::path name{ d_stack[2].str() };
    
    d_reg =  name.replace_extension(d_stack[3].str()).string();
}
