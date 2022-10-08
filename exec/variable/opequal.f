inline bool operator==(Variable const &lhs, Variable const &rhs)
{
    return *lhs.get() == *rhs.get();
}
