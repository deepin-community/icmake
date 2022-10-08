inline ExprType Symtab::typeOf(Location const &loc) const
{
    return d_var[loc.level][loc.idx].exprType;
}
