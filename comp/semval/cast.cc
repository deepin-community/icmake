#define XERR
#include "semval.ih"

SemVal SemVal::cast(Tokens::Tokens_ destType)
{
    switch (destType)
    {
        case Tokens::INT:
            toInt();
        break;

        case Tokens::STRINGTYPE:
            toStr();
        break;

        case Tokens::LIST:
            toList();
        break;

        case Tokens::BOOL:
            asBool();
        break;

        default:                            // avoids compiler warnings
        break;
    }

    return move(*this);
}
