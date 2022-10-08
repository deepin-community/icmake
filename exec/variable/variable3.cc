//#define XERR
#include "variable.ih"

Variable::Variable(Variable &&tmp)
:
    unique_ptr<VarBase>{ move(tmp) }
{}
