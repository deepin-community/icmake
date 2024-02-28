//#define XERR
#include "tools.ih"

string Tools::command(string const &moldCmd, string const &dollar1, 
                                             string const &dollar2)
{
    string cmd{ moldCmd };

    cmd.replace(cmd.find("$1"), 2, dollar1);
    cmd.replace(cmd.find("$2"), 2, dollar2);

    if (size_t pos = cmd.find("${ICMAKE_CPPSTD}"); pos != string::npos)
    {
        char const *envVar = getenv("ICMAKE_CPPSTD");
        if (envVar == 0)
        {
            envVar = getenv("ICMAKE_CXXFLAGS");
            if (envVar != 0)
                cout << "ICMAKE_CXXFLAGS is deprecated. "
                            "Use ICMAKE_CPPSTD instead" << endl;
        }
        string cxx{ envVar != 0 ? envVar : "" };
        cmd.replace(pos, sizeof("${ICMAKE_CPPSTD}") - 1, cxx);
    }

    return setPath(cmd);
}
