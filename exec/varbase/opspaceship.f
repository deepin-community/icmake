inline std::strong_ordering operator<=>(VarBase const &lhs, VarBase const &rhs)
{
    return lhs.vOrder(rhs);
}
