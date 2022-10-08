//#define XERR
#include "varbase.ih"

void VarBase::undefined() const
{
    throw Exception{} << "virtual function not overloaded";
}
