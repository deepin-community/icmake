                    // true: needs 1st #arguments argument, not counting iself
// static       
inline bool Builtin::argCount(Function function)
{
    return s_argCount.find(function) != s_argCount.end();
}
