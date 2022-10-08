//#define XERR
#include "symtab.ih"

void Symtab::functionParams()
{
    xerr("#levels: " << d_var.size() << ", #params: " << d_var.back().size());

    for (auto const &var: d_var.back())
        d_functions.paramType(var.varType);

    d_functions.checkOverload();
}
