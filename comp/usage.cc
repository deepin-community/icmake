#include "main.ih"

namespace {
char const info[] = R"_( [options] source dest
Where:
    [options] - optional arguments (short options between parentheses):
        --help (-h)          - provide this help
        --version (-v)       - show version information and terminate

    source    - source file to compile 
                (normally output from ICM-PP)
    dest      - name of the generated binary (.bim) file

)_";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info;
}



