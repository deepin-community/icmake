#define XERR
#include "symtab.ih"

SemVal Symtab::functionDefined(SemVal &statements)
{
    SemVal function = makeFrame();

// statements.bytes();

    statements.patchFalse(SemVal::END);

// xerr("patched false:");
// statements.bytes();

    function << statements;

    if (not SemVal::returns())
    {
        if (d_functions.isMain())
            function << Opcode::push_0 << Opcode::pop_reg;
        else if (d_functions.type() != e_void)
            Error::msg(Error::RETURN_TYPE) << d_functions.name() << "'\n";

        function << Opcode::ret;
    }

    d_var.resize(1);                // only keep the global variables
                                    // (i.e., nestLevel == 0)

    // reactivate semantic errors, see pendfunction.c

    return function;
}
