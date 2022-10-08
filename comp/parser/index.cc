//#define XERR
#include "parser.ih"

                                // rhs is the index
SemVal Parser::index(SemVal &lhs, SemVal &rhs) const
{
    rhs = pushPrint(rhs);

    if 
    (
        not (lhs.type() & (e_str | e_list)) // lhs must be string or list
        or 
        not (rhs.type() & e_int)            // rhs must be an int
    )
    {
        Error::msg(Error::INDEX_TYPE);
        return SemVal{ e_str | e_const };
    }

    Args args{ rhs };
    args.add(lhs);

    xerr("calling " << (lhs.type() & e_str ? "STR_EL" : "LIST_ELEMENT"));

    return args.callBuiltin(
                lhs.type() & e_str ? Builtin::STR_EL : Builtin::LIST_ELEMENT
            );
    
}





