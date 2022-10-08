#define XERR
#include "args.ih"

    // catExpressions is called for for- and if- statements's initialization
    // and increment sections. If an expression has no code, then the
SemVal Args::catExpressions(unsigned end)
{
    SemVal ret;

    for (unsigned idx = 0; idx != end; ++idx)
    {
        SemVal &arg = (*this)[idx];
        
//        if (arg.type() & (e_const | e_var))
//            continue;

//xerr("  type: " << arg.type() << ", code size: " << arg.code().size());
//arg.bytes();
        SemVal next = arg.exprStmnt();

        ret << next;
//ret.bytes();

//        arg.push();                // push the initialization code
//        ret << arg;
    }

    return ret;
}







