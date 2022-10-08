//#define XERR
#include "stack.ih"

Variable Stack::topMove() noexcept
{
    Variable ret = move(top());
    pop();
    return ret;
}
