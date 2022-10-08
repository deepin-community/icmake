// static
inline int Builtin::defaultArg(Function function)
{
    return function == MAKELIST;        // only MAKELIST uses default 1
                                        // other default 1st args are 0
}
