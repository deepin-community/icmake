//#define XERR
#include "stack.ih"

void Stack::push(Variable &&tmp)
{
    xerr("");
    d_stack.push_back(move(tmp));
    xerr("done");
}
