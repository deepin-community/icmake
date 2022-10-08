//#define XERR
#include "builtin.ih"

void Builtin::listElement()
{
    xerr(d_stack[2] << ", " << d_stack[3]);

    auto &strVector = d_stack[3].list();    // vector with list strings
    unsigned idx = d_stack[2].value();      // requested element

    d_reg =   idx >= strVector.size() ? string{} : strVector[idx];
}
