//#define XERR
#include "builtin.ih"

void Builtin::trimLeft()
{
    string const &str = d_stack[2].str();

    auto from = str.find_first_not_of(s_space);

    d_reg =  from == string::npos ? string{} : str.substr(from);
}
