inline void SemVal::addPatchFalse(Opcode::Byte jmpcode)
{
    addPatch(d_patchFalse, jmpcode);
}
