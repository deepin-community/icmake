inline bool Symtab::contains(std::string const &ident) const
{
    return find(ident) != end();
}
