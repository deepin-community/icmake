//#define XERR
#include "builtin.ih"

void Builtin::gets()
{
    string line;
    getline(cin, line);

    d_reg = move(line);
}
