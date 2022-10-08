//#define XERR
#include "list.ih"

List::List(vector<string> &&tmp)
:
    d_list(move(tmp))
{}
