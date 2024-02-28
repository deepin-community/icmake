//#define XERR
#include "tools.ih"

// static
string Tools::compilerSpec(char const *arg1, string const &stdCmd)
{
    string cmd;

    if (arg1 == 0)
        cmd = stdCmd;                  // use the std. if nothing's specified
    else
    {
        cmd = arg1;
        if (cmd.find("f:") == 0)                // file specified
        {
            ifstream in{ Exception::factory<ifstream>(cmd.substr(2)) };
            getline(in, cmd);
        }

        if (cmd.find("$1") == string::npos or cmd.find("$2") == string::npos)
            throw Exception{} << '`' << cmd << "' requires $1 and $2";
    }

    return cmd;
}
