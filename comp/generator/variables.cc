//#define XERR
#include "generator.ih"

void Generator::variables()
{
    d_header.variables = d_bim.tellp();

    for (auto const &var: d_symtab.globalVars())
        d_bim << as<char>(var.varType & e_mask);
}
