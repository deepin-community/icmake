//#define XERR
#include "tools.ih"

string &Tools::setPath(string &cmd)
{
    size_t pos = cmd.find_first_of(" \t");
    if (pos == string::npos)
        return cmd;

    string prog = cmd.substr(0, pos);

    if (exists(prog))
        return cmd;                     // already an existing program

    string path;
    char const *env = getenv("PATH"); 
    if (env == 0)                       // no PATH, so not searchable. If prog
        return cmd;                     // existed it's already returned

    path =  env;
    size_t from = 0;
    while (true)
    {
        size_t to = path.find(':', from);

        if (to == string::npos)
            to = path.length();

        string next = path.substr(from, to - from) + '/' + prog;
        if (exists(next))
        {
            cmd.replace(0, pos, next);
            break;
        }
    
        if (to == path.length())
            break;

        from = to + 1;
    }

    return cmd;
}

