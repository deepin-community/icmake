#define XERR
#include "symtab.ih"

namespace
{
    Symtab::Var notFound{ "", e_null, 0xc000 };
}

Symtab::Var const &Symtab::findVar(std::string const &name) const
{
                    // visit all VarVects from the last to the first
    for (unsigned level = d_var.size(); level--; )
    {
        if                              // if found, return the Var
        (
            int idx = find(d_var[level], name); 
            idx != -1
        )
            return d_var[level][idx];
    }

    return notFound; 
}
