#define XERR
#include "main.ih"

// When called from icmake: the bim-file must be the first argument following
// icmake's -e option. The initial .bim file and any subsequent arguments 
// are passed to icm-exec
//
// When called directly as '/usr/lib/icmake/icm-exec /tmp/input.bim:
//     ICM-EXEC ARGS: /usr/lib/icmake/icm-exec /tmp/input.bim 
// arguments:
//     nargs: 1, args: /tmp/input.bim

// When called as 'icmake -e /tmp/input.bim:
//     ICM-EXEC ARGS: /usr/lib/icmake/icm-exec /tmp/input.bim 
// program name:
//     icm-exec
// arguments:
//     nargs: 1, args: /tmp/input.bim

// When called as 'icmake -e /tmp/input.bim -t:
//     ICM-EXEC ARGS: /usr/lib/icmake/icm-exec /tmp/input.bim -t
// program name:
//     icm-exec
// arguments:
//     nargs: 1, args: /tmp/input.bim
// and /tmp/input.bim is removed

namespace
{
    option options[] =
    {
        { "help",               no_argument, 0, 'h' },
        { "no-version-check",   no_argument, 0, 'n' },
        { "version",            no_argument, 0, 'v' },
        { 0 }
    };
}

int main(int argc, char **argv)
try
{
    int opt;
    bool versionCheck = true;

    string program{ basename(*argv) };

    opterr = 0;
    while (true)
    {
        opt = getopt_long(argc, argv, "+hnv", options,  0);

        if (opt == -1)
            break;

        switch (opt)
        {
            case 'h':
                usage(program);
            return 0;

            case 'v':
                cout << program << " V" VERSION "\n";
            return 0;

            case 'n':
                versionCheck = false;
            break;

            case '?':
            throw Exception{} << '`' << argv[optind] << 
                        "': not a valid icm_exec option";
        };
    }

    if (optind == argc)
    {
        usage(program);
        return 1;
    }

    cerr << hex;

    Stack stack(optind, argc, argv);

    // read the .bim-file header
    BimHeader bimHdr{ argv[optind], VERSION, versionCheck };

    CPU cpu{ bimHdr, stack };   // create the icmake cpu processing bim-file
                                // instructions. This bootstraps the cpu

    return cpu.run();           // run the program in the .bim file
}
catch (int ret)
{
    return ret;
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cout << "\n"
            "fatal: unaccounted for exception\n";
    return 1;
}

