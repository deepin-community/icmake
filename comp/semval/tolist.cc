//#define XERR
#include "semval.ih"

void SemVal::toList()
{
    char const *type;

    switch (d_type & e_mask)
    {
        case e_list:                   // already a list, cast not needed
        return;

        case e_str:
            push();
            *this << Opcode::atol;
            d_type = e_list | e_stack ;
        return;
    
        case e_bool:
            type = "bool' to `list";
        break;

        case e_int:
            type = "int' to `list";
        break;

        default:                        // if e_null: invalid cast
            type = "void' to `int";
        break;
    }

    invalidCast(type);


}
