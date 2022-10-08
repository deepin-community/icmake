inline ExprType Symtab::globalType(unsigned idx) const
{
    return d_var[0][idx].varType & e_mask;
}
