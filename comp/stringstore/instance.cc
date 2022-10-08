//#define XERR
#include "stringstore.ih"

StringStore StringStore::s_stringStore;

StringStore &StringStore::instance()
{
    return s_stringStore;
}
