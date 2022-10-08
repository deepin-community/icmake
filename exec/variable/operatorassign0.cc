//#define XERR
#include "variable.ih"

Variable &Variable::operator=(Variable const &other)
{
    reset(other.get()->copy());
    return *this;
}
