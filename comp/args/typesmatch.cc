#define XERR
#include "args.ih"

bool Args::typesMatch(Builtin::Function function)
{
    if (function == Builtin::BuiltinSize)       // no such builtin function
        return false;
                                                // get the fun's args info
    auto const &funArgs = Builtin::arguments(function);  

    if (funArgs.size() == 0)
        return size() == 0;                     // no arguments: OK


    auto funBegin = funArgs.begin();            // initialize the types/args
    auto funEnd   = funArgs.end();              // iterators/indices

                                                // initial int not present?
                                                // then provide it:
    if ((*funBegin & e_bool) and not((*this)[0].type() & e_int))
        insert(                
            begin(),
            SemVal{ e_int | e_const, Builtin::defaultArg(function) }
        );

    unsigned argBegin = 0;
    unsigned argEnd = size();

//    xerr("funtypes:");
//    for (auto iter = funBegin; iter != funEnd; ++iter)
//        cerr << *iter << ' ';
//    cerr << '\n';
                                                // funBegin, argBegin move up
    if (not initialTypes(function, funBegin, funEnd, argBegin, argEnd))
        return false;

//xerr("funargs: " << (funEnd - funBegin) << ", args: " << (argEnd - argBegin));

    // funBegin == funEnd or points beyond e_null
    // argBegin is the index of the next argument to check

    return function == Builtin::MAKELIST ?      // handle MAKELIST
                makelist(funBegin, funEnd, argBegin, argEnd)
            :
                trailingTypes(funBegin, funEnd, argBegin, argEnd);
}






