//#define XERR
#include "stack.ih"

//         ... previously pushed stuff
//         ... args
// BP:     [ old frame BP ]
//         ... whatever

void Stack::popBP()
{
    //xerr("current BP = " << d_BP);

    d_stack.resize(d_BP + 1);       // remove local variables

    d_BP = top().value();           // restore BP so it points at the previous 
                                    // stack frame
    //xerr("next  BP = " << d_BP);

    pop();

    xerr("done: BP = " << d_BP << ", size: " << d_stack.size());
}

