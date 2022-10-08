#include "exprtype.ih"

ostream &operator<<(ostream &out, ExprType type)
{
    if (type & e_null)
        return out << "void";

out << "[ ";

    if (type & e_int)
        out << "int ";
    else if (type & e_str)
        out << "string ";
    else if (type & e_list)
        out << "list ";

    if (type & e_bool)
        out << "bool ";

    if (type & e_const)
        out << "const ";
    else if (type & e_var)
        out << "var ";
    else if (type & e_reg)
        out << "reg ";
    else if (type & e_stack)
        out << "stack ";

    if (type & e_prefix)
        out << "prefix ";
    else if (type & e_postfix)
        out << "postfix ";
    else if (type & e_order)
        out << "order ";
    else if (type & e_printf)
        out << "printf ";
    else if (type & e_fprintf)
        out << "fprintf ";

    return out << ']';
}






