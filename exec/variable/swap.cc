//#define XERR
#include "variable.ih"

void Variable::swap(Variable &other)
{
    unique_ptr<VarBase>::swap(other);
}
