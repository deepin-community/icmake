//#define XERR
#include "builtin.ih"

void Builtin::resize()
{
    string str{ d_stack[2].str() };

    int16_t size = d_stack[3].value();        // new value

    if (size < 0)
        size = 0;

    str.resize(size, ' ');

    d_reg = move(str);
}
