//#define XERR
#include "builtin.ih"

// at stack[from] the # arguments to process is stored. 
// the 1st arg is therefore at from + 1

void Builtin::insertReplace(ostream &out, string arg, size_t from) const
{
    while (s_percent << arg)                        // find a %\d+ match
    {
        size_t idx = stoul(s_percent[1]);

        auto pos = s_percent.position(0);           // get the indices

        out << arg.substr(0, pos.first);            // insert info up to the %
        out << d_stack[from + idx];                 // insert the arg. value

        arg.erase(0, pos.second);                   // remove the processed
                                                    // %\d 
    }

    out << arg;                                     // insert the tail
}
