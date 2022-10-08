#define XERR
#include "builtin.ih"

// x=y: adds or replaces x in the environment with y
// x  : removes x from the environment

void Builtin::putEnvironment()
{
    string arg = d_stack[2].str();      // get the spec
    if (arg.empty())
    {
        d_reg = 1;                      // empty spec: return 1
        return;
    }

    if (!setEnv(arg))                   // not set/change a specification
        removeEnv(arg);                 // then remove it

    d_reg = 0;
}
