inline bool SemVal::isLvalue(Opcode::Byte opcode) const
{
    return isLvalue(Opcode::mnemonic(opcode));
}
