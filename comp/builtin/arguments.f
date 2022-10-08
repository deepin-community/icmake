// static
inline Builtin::Args const &Builtin::arguments(Function function)
{
    return s_builtin[function].args;
}
