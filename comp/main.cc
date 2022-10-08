#define XERR
#include "main.ih"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("hv", longOpts, longEnd, argc, argv);
    arg.versionHelp(usage, VERSION, 2);

    Parser parser{ arg[0] };

//    parser.setDebug(true);
    if (parser.parse())
    {
        cerr << "error(s) encountered\n";
        return 1;
    }

    Generator generator{ arg[1], parser };

    if (not generator.backend())
        return generator.noBim();
}
catch(int value)
{
    return value;
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "unexpected exception\n";
    return 1;
}
