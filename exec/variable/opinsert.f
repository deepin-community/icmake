inline std::ostream &operator<<(std::ostream &out, Variable const &var)
{
    return var.get()->insertInto(out);
}
