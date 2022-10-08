//#define XERR
#include "parser.ih"

// see README.stackframe for the organization of the stack frames

SemVal Parser::variable(string const &name)
{
    // `name' may be '(f)printf' in which case a SemVal whose type is 
    // e_(f)printf is returned, which is only recognized by the << operator

    Symtab::Var var = d_symtab.findVar(name);

    if (var.location != 0xc000)
        return SemVal{ var.varType, var.location };

    if (name == "printf")
        return SemVal{ e_printf };          // (f)printf insertions don't
                                            // have return values: cannot
    if (name == "fprintf")                  // be nested in expressions
        return SemVal{ e_fprintf };

    Error::msg(Error::UNDEFINED_VAR) << name << "'\n";
    return SemVal{ e_int | e_var };         // pseudo int-var return
}





