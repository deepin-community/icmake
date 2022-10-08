//#define XERR
#include "stack.ih"

void Stack::push(Variable const &var)
{
    xerr("");
    d_stack.push_back(var);
}
