// #define XERR
#include "variable.ih"

Variable::Variable(Variable const &other)
:
    unique_ptr<VarBase>{ other.get()->copy() }
{}
