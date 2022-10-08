//#define XERR
#include "functions.ih"

Functions::Overload const *Functions::find(std::string const &name) const
{
    auto iter = d_functions.find(name);

    return iter == d_functions.end() ? 0 : &iter->second;
}
