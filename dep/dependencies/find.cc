//#define XERR
#include "dependencies.ih"

void Dependencies::find()
{
    directDependencies();           // direct dependencies of .ih files
                                    // on other .ih files
    impliedDependencies();

    g_log << level(V4) << "Header file inspection completed\n";
}
