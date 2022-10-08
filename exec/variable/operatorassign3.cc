//#define XERR
#include "variable.ih"

Variable &Variable::operator=(string &&str)
{
    Variable tmp{ new String{ move(str) } };    
    swap(tmp);
    return *this;
}
