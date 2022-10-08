//#define XERR
#include "semval.ih"

void SemVal::toStr()
{
    char const *type;

    switch (d_type & e_mask)
    {
        case e_str:                     // already a str, cast not needed
        return;

        case e_bool:                    // bools become ints
            bool2int();
        [[fallthrough]];

        case e_int:                     // (string)int: OK
            if (d_type & e_const)
                set(e_str | e_const, 
                    StringStore::instance().offset(to_string(d_value))
                );
            else
            {
                push();
                *this << Opcode::itoa;
                d_type = e_str | e_stack;
            }
        return;
                
        case e_list:                    // (stringlist not implemented
            type = "list' to `string";
        break;

        default:                        // if e_null: invalid cast
            type = "void' to `int";
        break;

    }

    invalidCast(type);
}
