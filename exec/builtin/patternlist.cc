#define XERR
#include "builtin.ih"

//      stack[2]   : Opcode::hlt       (already handled by makeList())
//      stack[3]   : filemask value 
//      stack[4]   : pattern

vector<string> Builtin::patternList() const
{
    auto const &specs = s_globSpecs.find(d_stack[3].value());

    if (specs == s_globSpecs.end())     // invalid filemask 
        return vector<string>{};
    
    Glob gl{ specs->second.type, d_stack[4].str().c_str(), 
             specs->second.flags };

    return vector<string>{ gl.begin(), gl.end() };
}






