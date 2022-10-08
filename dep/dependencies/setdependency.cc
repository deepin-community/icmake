//#define XERR
#include "dependencies.ih"

    // if dirName is a project directory then directory[idx] depends on
    // that directory, and dependency[idx][dirname's idx] is set to 'true'

void Dependencies::setDependency(size_t idx, string const &dirName)
{
    auto iter = std::find(d_directory.begin(), d_directory.end(), dirName);

    if (iter != d_directory.end())          // dirName is a project dir.
        d_dependency[idx][iter - d_directory.begin()] = true;   
                                            // set the dependency.

    // (dirName may be directory not listed in CLASSES: that's OK)
}
