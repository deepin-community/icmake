//#define XERR
#include "varbase.ih"

// virtual
vector<string> const &VarBase::vList() const
{
    xerr("");
    undefined();
}
