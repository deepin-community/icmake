//#define XERR
#include "varbase.ih"

// virtual
int &VarBase::vValueRef()
{
    xerr("");
    undefined();
}
