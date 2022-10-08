#define XERR
#include "semval.ih"

void SemVal::push()
{
    if (d_type & e_stack)           // expression already pushed
    {
        if (d_type & e_bool)
            bool2int();
        return;
    }

    switch (d_type & 
            (e_const | e_var | e_bool | e_reg | e_prefix | e_postfix))
    {
        default:                // handles e_void types: no actions
        return;

        case e_const:
            *this << (d_type & e_int ? 
                            Opcode::push_imm 
                        : 
                            Opcode::push_strconst) <<
                     as<short>(d_value);
        break;

        case e_var:
            if (not copiedVar())
                *this << Opcode::push_var << as<short>(d_value);
        break;

        case e_bool:
            bool2int();
        return;                 // bool2int -> alredy e_stack type
              
        case e_reg:
            *this << Opcode::push_reg;
        break;

        case e_prefix:
                    // prefix: first do ++, then push the variable
                    //         holding the result of the expression
            *this << Opcode::push_var << as<short>(d_value);
        break;

        case e_postfix:
        {
                    // postfix: first push the variable, then compute the
                    //          result of the expression
            SemVal pre{ e_int };    // pseudo type for the insertion below:
            pre << Opcode::push_var << as<short>(d_value);
            pre << *this;
            *this = move(pre);
        }
        break;
    }

    stackType();
}

