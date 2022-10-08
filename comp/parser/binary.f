inline SemVal Parser::binary(SemVal &lhs, 
                             Opcode::Byte opcode, SemVal &rhs) const
{
    return pushPrint(lhs).binary(opcode, pushPrint(rhs));
}
