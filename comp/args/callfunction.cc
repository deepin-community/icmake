//#define XERR
#include "args.ih"

bool Args::callFunction(SemVal &ret, Functions::Info const &info)
{
    uint8_t size = pushArgs(ret);

    ret << Opcode::call << as<short>(info.offset);

    if (size > 0) 
        ret << Opcode::asp << size;

    ret.setType(e_reg | info.returnType);

    return true;
}
