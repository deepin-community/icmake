//#define XERR
#include "unassembler.ih"

void UnAssembler::pop_var() const
{
    handleVar("pop");
}
