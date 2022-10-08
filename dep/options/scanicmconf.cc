//#define XERR
#include "options.ih"

void Options::scanIcmconf()
{
    auto in{ Exception::factory<ifstream>(d_icmconf) };

    string line;
    
    while (getline(in, line))
    {
        if (not (s_icmconf << line))            // no match
            continue;                           // inspect the next line

        auto iter = s_icmconfEntry.find(s_icmconf[1]);
        if (iter != s_icmconfEntry.end())
            (this->*(iter->second))();          // process s_icmconf[2] if
                                                // needed
    }
}
