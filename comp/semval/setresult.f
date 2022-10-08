inline void SemVal::setResult(ExprType result) // e_var, e_stack, ...
{
    d_type = (d_type & e_mask) | result;
}
