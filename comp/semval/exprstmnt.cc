#define XERR
#include "semval.ih"

    // called by Parser::exprStmnt

SemVal SemVal::exprStmnt()
{
    bool2int();

    if (d_code.size())
    {
            // current semval: last value on the stack: pop it instead of
            // adding 1 to the SP
        if (d_lastOpcode == Opcode::copy_var)
            d_code[d_code.size() - sizeof(int16_t) - 1] = d_lastOpcode = 
                                                            Opcode::pop_var;
        else if ( 
            (d_type & e_stack) 
            and 
            not (d_type & (e_prefix | e_postfix))
        )
            *this << Opcode::asp << as<uint8_t>(1);
    }

    return move(*this);
}
