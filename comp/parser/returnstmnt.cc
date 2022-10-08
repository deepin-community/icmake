//#define XERR
#include "parser.ih"

SemVal Parser::returnStmnt(Tokens::Tokens_ type, SemVal &expr) const
{
    xerr("before push: " << expr.type());

    expr.push();                    // nothing's pushed when e_void

    xerr("after push: " << expr.type());

    SemVal ret;
                                                        
    if (type == Tokens::RETURN)
        ret = functionReturn(expr);

    else if (equalMask(expr.type(), e_int))      // EXIT: must have ints
        ret << expr << Opcode::pop_reg << Opcode::exit;

    else    
        Error::msg(Error::EXIT_TYPE) << d_functions.name() << "'\n";
        
    ret.ends();
    
    return ret;
}
