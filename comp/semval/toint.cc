//#define XERR
#include "semval.ih"

void SemVal::toInt()
{
    char const *type;

    switch (d_type & e_mask)
    {
        case e_int:
        return;

        case e_bool:
            bool2int();                     // d_type: e_int | e_stack
        return;

        case e_str:
            if (d_type & e_const)           // int-representation of a 
                set(e_int | e_const,        // constant string
                    StringStore::instance().asInt(d_value));   
            else
            {
                push();
                *this << Opcode::atoi;
                d_type = e_int | e_stack;   // atoi replaces the stacktop
            }
        return;

        case e_list:
            type = "list' to `int";
        break;

        default:                            // if e_null: invalid cast
            type = "void' to `int";
        break;
    }

    invalidCast(type);
}
