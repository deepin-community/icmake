//#define XERR
#include "builtin.ih"

// the stack's top contains the filename, the element before that
// the new basename. 

void Builtin::changeBase()
{
    filesystem::path name{ d_stack[2].str() };
    string ext = name.extension();      // keep the extension
                                        // at stacktop - 1: the new basename
    d_reg =  name.replace_filename(d_stack[3].str()).string() + ext;
}
