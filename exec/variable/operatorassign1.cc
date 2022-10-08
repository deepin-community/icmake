//#define XERR
#include "variable.ih"

Variable &Variable::operator=(int value)
{
    Variable tmp{ new Int{ value } };    
    swap(tmp);
    return *this;
}
