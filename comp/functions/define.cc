//#define XERR
#include "functions.ih"

void Functions::define(ExprType type, string const &name)
{
    if (name == "main")
        defineMain(type);
    else
    {
                                                // this function's overloads
        d_overload = d_functions.emplace(name, Overload{}).first;    
        d_overload->second.push_back(
                 Info{ as<unsigned>(d_code.size() + sizeof(Header)), type }
                                );
        d_info = &d_overload->second.back();    // ->the Info under
                                                //   construction 

        xerr(name << " returns " << d_info->returnType);
    }
}
