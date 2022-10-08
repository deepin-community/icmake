#define XERR
#include "parser.ih"

    // expr's value already pushed
    //
SemVal Parser::functionReturn(SemVal &expr) const
{
    // EXIT already handled

    if (not voidMask(d_functions.type(), expr.type()))
        Error::msg(Error::RETURN_TYPE) << d_functions.name() << "'\n";

    else if (d_functions.type() != e_void)
        expr << Opcode::pop_reg;

    else if (
        d_functions.isMain() 
        and 
        d_functions.mainInfo().returnType == e_void
    )
        expr << Opcode::push_0 << Opcode::pop_reg;

    expr << Opcode::ret;

    return move(expr);
}
