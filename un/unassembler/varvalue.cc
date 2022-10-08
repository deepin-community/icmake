#include "unassembler.ih"

// static
void UnAssembler::varValue(VarType type, int16_t idx)
{
    char sign = '+';

    switch (type)
    {
        case GLOBAL:
            cout << '[' << setw(4) << idx << ']';
        return;

        case LOCAL:
            sign = '-';
            idx = -idx;
        break;

        case ARG:
        break;
    }

    cout << "[bp" << sign << setw(4) << idx << ']';
}




