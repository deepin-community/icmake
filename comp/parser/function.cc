#define XERR
#include "parser.ih"

SemVal Parser::function(string const &name, Args &&args) const
{
    SemVal ret;

//xerr("calling " << name << ", args:");
//for (SemVal const &arg: args)
//arg.bytes();

    for (auto &arg: args)
        arg = pushPrint(arg);

    // special case: 'element(idx, list or string)'  calls index
    if 
    (
        name == "element" and args.size() == 2 
        and 
        (args[0].type() & e_int) and args[1].type() & (e_str | e_list)
    )
        return index(args[1], args[0]);

    if (
        not args.builtin(ret, name)     // ret is called using args
        and                             
        not args.function(ret, d_functions.find(name))  // (same)
    )
        Error::msg(Error::UNDEFINED_FUNCTION) << name <<
                                        "' (maybe types of args mismatch)\n";

//    SemVal::pushDead();           ???

    return ret;
}
