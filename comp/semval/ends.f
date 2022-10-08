inline void SemVal::ends()
{
    d_state = DEAD | RETURN;
}
