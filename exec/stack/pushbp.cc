//#define XERR
#include "stack.ih"

void Stack::pushBP()
{
    xerr("size: " << d_stack.size() << ", BP = " << d_BP);

    d_stack.push_back(new Int{ as<int>(d_BP) });     // save the current BP

    xerr("BP pushed");

    d_BP = d_stack.size() - 1;                  // BP points at the saved BP 
                                                // offset

    xerr("done BP = " << d_BP << ", size = " << d_stack.size());
}
