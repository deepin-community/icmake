inline bool voidMask(ExprType lhs, ExprType rhs)
{
    return equalMask(lhs, rhs) or (lhs == e_void and rhs == e_void);
}
