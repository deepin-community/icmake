//#define XERR
#include "main.ih"

    // argument 1 is -h or --help ?     -> usage
    // no arguments ?
    //      no icmconf available -> error
    // start icmconf with the provided arguments

int main(int argc, char **argv)
{
    if (argc > 1 and (argv[1] == "-h"s or argv[1] == "--help"s))
    {
        usage(argv[0]);
        return 0;
    }

    if (not Tools::exists("icmconf"))
    {
        cerr << "no `icmconf' file in the current directory\n";
        return 1;
    }

    string cmd{ "/usr/bin/icmake -t. " LIBDIR "/icmbuild" };
    
    for_each(argv + 1, argv + argc, 
        [&](char *arg)
        {
            (cmd += ' ') += arg;
        }
    );

    Process icmbuild{ cmd };
    icmbuild.start(Process::DIRECT, Process::USE_PATH);

    cerr << "Could not execute `" << cmd << "'\n";
    return 1;
}
