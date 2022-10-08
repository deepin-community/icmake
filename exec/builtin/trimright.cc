//#define XERR
#include "builtin.ih"

void Builtin::trimRight()
{
    string const &str = d_stack[2].str();

    auto to = str.find_last_not_of(s_space);

    d_reg =  to == string::npos ? string{} : str.substr(0, to + 1);
}
