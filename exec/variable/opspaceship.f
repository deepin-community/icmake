inline std::strong_ordering operator<=>(Variable const &lhs, 
                                         Variable const &rhs)
{
    return *lhs.get() <=> *rhs.get();
}
