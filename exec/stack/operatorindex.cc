//#define XERR
#include "stack.ih"

Variable &Stack::operator[](int index)
{
                                // negative indices refer to local vars
                                // which are at locations beyond d_bp

    xerr("bp: " << d_BP << ", index: " << index << ", element at "\
          << (d_BP - index));

    return d_stack[d_BP - index];
}

