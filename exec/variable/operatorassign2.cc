//#define XERR
#include "variable.ih"

Variable &Variable::operator=(std::string const &str)
{
    Variable tmp{ new String{ str } };    
    swap(tmp);
    return *this;
}
