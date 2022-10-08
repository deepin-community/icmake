//#define XERR
#include "semval.ih"

//static
void SemVal::resetDead()
{
    s_deadCode = vector<bool>(1);
    s_returns = false;
}
