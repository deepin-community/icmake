// static
inline char const *BuiltinFunctions::name(uint8_t index)
{
    return s_name[index] + (s_name[index][0] == ' ');
}
