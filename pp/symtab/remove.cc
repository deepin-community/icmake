//#define XERR
#include "symtab.ih"

void Symtab::remove(string const &ident)
{
    if (auto iter = find(ident); iter != end())
        erase(iter);
}
