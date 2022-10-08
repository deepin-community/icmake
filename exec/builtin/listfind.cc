//#define XERR
#include "builtin.ih"

// the index of the first element in the stack.top()'s list which is equal 
// to the stack[-1] string
// 
// -1 is returned if such an element was not found.

void Builtin::listFind()
{
    auto const &list = d_stack[2].list();
    
    auto iter = find(list.begin(), list.end(), d_stack[3].str());

    d_reg = iter == list.end() ? -1 : iter - list.begin();
}
