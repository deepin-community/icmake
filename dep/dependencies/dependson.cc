//#define XERR
#include "dependencies.ih"

void Dependencies::dependsOn(string const &line, size_t idx)
{
    if (not (s_include << line))    // line isn't a local include directive
        return;

    xerr("line `" << line << "': regex count = " << s_include.end());

    switch (s_include.end())
    {
        case 3:                 // a local header file (#include "hdr")
            localHeader(idx, s_include[2]);
        break;

        case 4:                 // a main dir. header (#include "../hdr")
            d_dependency[idx][0] = true;
        break;

        case 6:                 // main includes a subdir header
                                // (#include "sub/hdr")
            setDependency(0, s_include[4]);
        break;

        case 8:                 // this dir. includes a subdir header
                                // (#include "../sub/hdr")
            setDependency(idx, s_include[6]);
        break;
    }
}
