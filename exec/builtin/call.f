inline void Builtin::call(size_t funIdx)
{
    (this->*s_function[funIdx])();
}
