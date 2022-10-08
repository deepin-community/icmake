#define XERR
#include "splitter.ih"

bool Splitter::writable(string &dirName)
{
    if (Stat{ dirName }.isType(Stat::DIRECTORY) 
        and
        access(dirName.c_str(), R_OK | W_OK | X_OK) == 0
    )
    {
        if (dirName.back() != '/')
            dirName += '/';
        return true;
    }

    return false;
}
