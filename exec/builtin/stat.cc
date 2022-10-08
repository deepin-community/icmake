#define XERR
#include "builtin.ih"

//  This function expects a filename as last pushed
//  value. The file attributes are retrieved by Stat
//  A list is returned, containing:
//
//      [0]: the file's attributes.
//      [1]: the file size.

void Builtin::stat()
{
    int check = d_stack[2].value();
    Stat st{ d_stack[3].str() };

    if (not st)
    {
        if (check == P_CHECK)
            throw Exception{} << "can't stat `" << st.name() << '\'';
        d_reg = vector<string>{ "-1" };
    }
    else
    {
        auto &stat = st.statStruct();
        d_reg = vector<string>{ to_string(stat.st_mode),
                                to_string(stat.st_size) };
    }
}
