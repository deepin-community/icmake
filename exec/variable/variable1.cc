//#define XERR
#include "variable.ih"

Variable::Variable(VarBase *ptr)
:
    unique_ptr<VarBase>{ ptr != 0 ? ptr : new Int }
{}


