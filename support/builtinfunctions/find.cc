//#define XERR
#include "builtinfunctions.ih"

BuiltinFunctions::Function BuiltinFunctions::find(string const &name)
{
                    // added space to allow 'backtick' function names
    string const &searchName =  name == "`" ? " backtick"s : name;

    auto iter = find_if(s_name, s_name + BuiltinSize, 
        [&](char const *funName)
        {
            return searchName == funName;
        }
    );

    return as<Function>(iter - s_name);
}
