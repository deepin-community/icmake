// static
template <typename Type>
inline void Tools::append(std::string &dest, Type value)
{
    append<Type, Type>(dest, value);
}
