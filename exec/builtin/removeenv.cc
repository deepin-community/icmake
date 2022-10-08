#define XERR
#include "builtin.ih"

    // an environ spec without '=' was found
void Builtin::removeEnv(string &spec)
{
    putenv(&spec.front());          // remove the environment specification

    if (auto iter = d_environment.find(spec); iter != d_environment.end())
        d_environment.erase(iter);
}
