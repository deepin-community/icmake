inline void SemVal::stackType()
{
    d_type = (d_type & e_mask) | e_stack;
}
