inline bool Args::equalTypes(Builtin::ArgsIter funIter, unsigned argIdx) const
{
    return (*funIter &  (*this)[argIdx].type()) != e_null;
}
