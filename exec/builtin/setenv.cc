//#define XERR
#include "builtin.ih"

bool Builtin::setEnv(string const &spec)
{
    size_t pos = spec.find('=');       // find the var/value separator

    if (pos == string::npos)            // not found, so remove the env.
        return false;

    putenv(&(d_environment[spec.substr(0, pos)] = spec).front());
    return true;
}
