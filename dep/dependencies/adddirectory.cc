//#define XERR
#include "dependencies.ih"

void Dependencies::addDirectory(string const &dirname)
{
    if (not dirname.empty())
    {
        if (
            std::find(d_directory.begin(), d_directory.end(), dirname) 
            != 
            d_directory.end()
        )
            return;                     // the class was already present

        if (dirname.length() > d_dirWidth)
            d_dirWidth = dirname.length();

        d_directory.push_back(dirname);
    }
}
