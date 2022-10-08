//#define XERR
#include "builtin.ih"

//      stack[5]   : reference filename

vector<string> Builtin::patternCompare(
                    bool (*keep)(string const &entry, Stat const &reference)
                ) const
{
                                            // last modification time of the 
                                            // reference file
    Stat reference{ d_stack[5].str() };

    vector<string> ret = patternList();     // entries matching the pattern

                                            // move all entries that shouldn't
    auto iter = remove_if(ret.begin(), ret.end(),   // be kept to the back
        [&](string const &entry)
        {
            return not keep(entry, reference);
        }
    );
        
    ret.resize(iter - ret.begin());         // reduce to the remaining size

    return ret;
}
