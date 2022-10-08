#define XERR
#include "builtin.ih"

void Builtin::getEnvironVar()
{
    char const *env = getenv( (char *)d_stack[2].str().c_str() );

    d_reg = 
        env == 0 ?
            vector<string>{ "0", "" }           // no such env. var
        :
            vector<string>{ "1", env };         // return the env.var's value
}






