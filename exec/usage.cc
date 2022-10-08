//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"( [options] bimfile [args]
Where:
    [options] - optional arguments (short options between parentheses):
        --no-version-check (-n) - the bimfile's main version may differ from
                                  )";

char const info2[] = R"()
        bimfile - binary icmake '.bim' file (default extension: .bim)
        [args]  - optional additional arguments passed on to the bimfile

)";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info << progname << "'s main version (" << 
                                 stoul(VERSION) <<  info2;
}
