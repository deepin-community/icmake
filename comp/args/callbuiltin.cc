//#define XERR
#include "args.ih"

SemVal Args::callBuiltin(Builtin::Function function)
{
    SemVal ret;

    // list makelist([int type = O_FILE], string mask)
    // list makelist([int  type = O_FILE,] string mask, {newer,older},
    //                string comparefile)
    // the run-time makelist function needs a (hidden, not configurable)
    // first argument S_IEXEC (= 32, see scaneer/lexer)


    if (function == Builtin::MAKELIST)
        return callMakelist();

    uint8_t nArgs = pushArgs(ret);

    if (Builtin::argCount(function))
    {
        SemVal count{ e_int | e_const, nArgs++ };
        count.push();
        ret << count;
    }

    ret << Opcode::call_rss << as<uint8_t>(function);

    if (nArgs != 0)
        ret << Opcode::asp << nArgs;

    ret.setResult(Builtin::returnType(function));

xerr("returning type " << ret.type());

    return ret;
}





