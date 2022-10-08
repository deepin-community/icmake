inline constexpr ExprType operator|(ExprType lhs, ExprType rhs)
{
    return static_cast<ExprType>(
                static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)
            );
}
