//#define XERR
#include "builtin.ih"

void Builtin::listUnion()
{
    vector<string> ret{ d_stack[2].list() };        // the source list

    if (d_stack[3].isString())                      // the added element(s)
        unionAdd(ret, d_stack[3].str());            // a string: add it
    else
    {
        for (auto const &str: d_stack[3].list())    // a list...
            unionAdd(ret, str);                     // add its elements
    }

    d_reg = move(ret);
}
