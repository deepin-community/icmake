#include "main.ih"

namespace {
char const info[] = R"( [options] bimfile
Where:
    [options] - optional arguments (short options between parentheses):
        --help (-h)             - provide this help
        --no-version-check (-n) - the bimfile's main version may differ from
                                  )";

char const info2[] = R"()
        --version (-v)          - show version information and terminate
    
   bimfile - binary icmake '.bim' file (default extension: .bim)

)";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) <<
            info << progname << "'s main version (" << 
            stoul(VERSION) <<  info2;
}
