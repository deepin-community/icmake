//#define XERR
#include "stringstore.ih"

StringStore::StringStore()
:
    d_string(1, { 0, "" }),
    d_offset(1),
    d_indexOf{ { 0, 0 } }
{}
