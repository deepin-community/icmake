//#define XERR
#include "parser.ih"

SemVal Parser::shiftOrPrint(SemVal &lhs, 
                            Opcode::Byte opcode, SemVal &rhs) const
{
    if (lhs.type() & e_printMask)               // lhs is a printf expression
    {
        if (opcode == Opcode::shl)              // new printf argument:
            return lhs.printfArg(rhs);          // add it to lhs, and done.

                                                // handle the >> operator:

        if (lhs.nPrintfArgs() > 0)              // printf has arguments: first
            lhs = pushPrint(lhs);               // handle the printf insertion
        else                                    // printf w/o arguments:
            Error::msg(Error::PRINTF_OPCODE);   // 'printf >>' is invalid
    }

    return lhs.binary(opcode, move(rhs));       // perform the >> operation
}
