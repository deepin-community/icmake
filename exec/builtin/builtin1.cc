//#define XERR
#include "builtin.ih"

Builtin::Builtin(Variable &reg, Stack &stack)
:
    d_orgDir(filesystem::current_path()),
    d_stack(stack),
    d_reg(reg)
{}
