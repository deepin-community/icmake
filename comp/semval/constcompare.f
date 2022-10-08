    // both types either int or string. 
    // list constants are always compared run-time

inline int SemVal::constCompare(SemVal const &rhs) const
{
    return (d_type & e_int) ? 
                d_value - rhs.value()
            :
                StringStore::instance().constCompare(d_value, rhs.value());
}
