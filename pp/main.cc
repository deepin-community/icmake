//#define XERR
#include "main.ih"

// main() checks if two arguments are present on the
// invoking command line. If not std in and std out are used.
// 
// The environment variable IM is inspected to ensure that
// included files are searched from this directory. When not set,
// included files are searched in the current directory.

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"define",           'd'},
        Arg::LongOption{"help",             'h'},
        Arg::LongOption{"version",          'v'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("d:hv", longOpts, longEnd, 
                                             argc, argv);

    arg.versionHelp(usage, VERSION, 2);

    State state;

    return state.run();
}
catch (int retValue)
{
    return retValue;
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "\n"
            "fatal: unaccounted for exception\n";
    return 1;
}

