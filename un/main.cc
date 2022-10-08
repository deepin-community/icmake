#define XERR
#include "main.ih"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"no-version-check", 'n'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("hnv", longOpts, longEnd, argc, argv);
    arg.versionHelp(usage, VERSION, 1);

    // read the .bim-file header, and construct the UnAssembler
    BimHeader bimHdr{ arg[0], VERSION, not arg.option('n') };

    UnAssembler unAssembler{ bimHdr };

    unAssembler.run(arg.basename());
}
catch (exception const &exc)
{
    cout << '\n' <<
            exc.what() << '\n';
    return 1;
}
catch (int exitValue)
{
    return Arg::instance().option("hv") ? 0 : exitValue;
}
catch (...)
{
    return 1;
}
