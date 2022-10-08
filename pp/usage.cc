#include "main.ih"

namespace {
char const info[] = R"_(" [options] input output
Where:
    [options] - optional arguments (short options between parentheses):

        --define=SYM (-d)     - defines preprocessor symbol SYM having 
                                value "1" 
        --help (-h)           - provide this help
        --version (-v)        - show version information and terminate
    
       input    - icmake script source file
       output   - preprocessed icmake script (ready to be passed to
                  icm-comp)

)_";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info;
}



