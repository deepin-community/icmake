//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [option] command
Where:
    [options] - optional arguments (short options between parentheses,
                                    only one option can be specified):
        --help (-h) - provide this help (ends `icmbuild')
                      [also shown if `icmconf', required by `icmbuild',
                       does not exist in the current working directory]
        -c          - clears the screen ('tput clear') just before starting
                      the compilation process
        -s          - strip the compilation products at their installation
                      directories 
    command:
        clean       - remove remnants of previous activities
        cleangch    - remove all precompiled header files
        cleantmp    - remove files created during compilation from TMP_DIR
                      (precompiled headers stored under TMP_DIR are kept
        install what where - install a compilation product
                      (this command may be preceded by option -s)
            what: use 'program', 'static', or 'shared' to install, resp., the
                   program, the static library, or the shared library
            where: path (directory) to install the compilation product in. The
                   path may start with ~/
        library     - build a static library (requires icmconf's LIBRARY
                      specification). When icmconf also specifies SHARED then
                      a shared library is also built
                      (this command may be preceded by option -c)
        program     - build a program (requires icmconf's MAIN specification)
                      (this command may be preceded by option -c)

)_";

}

void usage(std::string progname)
{
    if (size_t idx = progname.rfind('/'); idx != string::npos)
        progname.erase(0, idx + 1);

    Tools::usageTop(progname) << info;
}
