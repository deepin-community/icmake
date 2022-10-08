#define XERR
#include "scanner.ih"

namespace 
{
    string s_where;
    size_t s_lineNr;
}

string const &g_where = s_where;        // g_where and g_lineNr are used 
size_t const &g_lineNr = s_lineNr;      // by Error

void Scanner::setWhere() const
{
    s_lineNr = lineNr();
    s_where = filename() + " [line " + to_string(s_lineNr) + "]: ";
//xerr(s_where);
}
