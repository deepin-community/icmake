//#define XERR
#include "varbase.ih"

// virtual
int VarBase::vValue() const
{
    xerr("");
    undefined();
}
