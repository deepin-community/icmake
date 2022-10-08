//#define XERR
#include "varbase.ih"

// virtual
string const &VarBase::vStr() const
{
    xerr("");
    undefined();
}
