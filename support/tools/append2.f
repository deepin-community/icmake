// static
template <typename UseType, typename Type>
void Tools::append(std::string &dest, Type value)
{
    char *cp = reinterpret_cast<char *>(&value);
    dest += std::string{ cp, cp + sizeof(UseType) };
}
