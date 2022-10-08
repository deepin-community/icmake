//#define XERR
#include "builtin.ih"

void Builtin::listConstruct()
{
    xerr("");
    vector<string> vs;
    for (size_t begin = 3, end = begin + d_stack[2].value(); 
            begin != end; 
                ++begin
    )
        vs.push_back(d_stack[begin].str());

    xerr("1");
    d_reg = move(vs);
    xerr("2");
}
