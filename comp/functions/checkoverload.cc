//#define XERR
#include "functions.ih"

void Functions::checkOverload() const
{
xerr("start");
    if (d_info == &d_main)
    {
        checkMainParams();
xerr("end 1");
        return;
    }

    for (
        auto begin = d_overload->second.begin(), 
               end = d_overload->second.end() - 1; 
            begin != end; 
                ++begin)
    {
        if (begin->params == d_info->params)
        {
            Error::msg(Error::AMBIGUOUS_OVERLOAD) << d_overload->first << 
                                                                        "'\n";
xerr("end 2");
            return;
        }
    }

xerr("end 3");

}


