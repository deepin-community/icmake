#define XERR
#include "semval.ih"

void SemVal::addPatch(vector<unsigned> &patchVect, Opcode::Byte jmpcode)
{
    *this << jmpcode << as<short>(0);
    patchVect.push_back(d_code.size());
}
