inline SemVal &operator<<(SemVal &lhs, SemVal &rhs)
{
    return lhs.insert3(rhs);
}
