//#define XERR
#include "list.ih"

bool List::vBool() const 
{
    return not d_list.empty();
}
