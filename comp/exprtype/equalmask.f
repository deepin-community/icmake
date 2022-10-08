inline bool equalMask(ExprType lhs, ExprType rhs)
{
    return (lhs & rhs & e_mask) != e_null;
}
