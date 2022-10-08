//#define XERR
#include "unassembler.ih"

void UnAssembler::handleVar(char const *instruction) const
{
    auto index = d_hdr.get<uint16_t>();       

    display4(index);
    cout << s_2;

    VarType type = varType(&index);

    switch (type)
    {
        case GLOBAL:
        {
            auto type = d_hdr.varType(index);   // get the global var. type
            cout << instruction << " global " << s_typeName[type] << ' ';
        }
        break;

        case LOCAL:
            cout << instruction << " local " << 
                        s_typeName[d_frame.type(index)] << ' ';
        break;

        case ARG:
            cout << instruction << " arg ";
        break;
    }

    varValue(type, index);                  // [var. specification]
}
