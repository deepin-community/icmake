//#define XERR
#include "variable.ih"

Variable &Variable::operator=(vector<string> &&vect)
{
    Variable tmp{ new List{ move(vect) } };    
    swap(tmp);
    return *this;
}
