// static
inline void SemVal::pushDead()
{
    s_deadCode.push_back(s_deadCode.back());
}
