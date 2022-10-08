#define XERR
#include "builtin.ih"

// This function is called at opcode op_strtok. The last pushed string is
// converted to a list, by splitting it according to the separators which are
// found in the one-but-last pushed string.

// When the separator-string is empty, then the string to split is split
// into separate characters.

void Builtin::strTok()
{
    string const &str = d_stack[2].str();
    string const &sep = d_stack[3].str();

    vector<string> ret;

    if (not sep.empty())
        String::split(&ret, str, String::TOK, sep.c_str());
    else
    {
        for (char ch: str)
            ret.push_back(string{ ch });
    }

    d_reg = move(ret);
}



