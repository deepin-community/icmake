#include <unistd.h>
#include <iostream>

using namespace std;

// see the comment at the end

int main(int argc, char **argv)
{
    cout << '\n';

    opterr = 0;                         // no errors

    while (getopt(argc, argv, "nt:") != -1)
        ;

    unsigned optIdx;

    optind = 1;                         // return to get the actual indices
    while (true)
    {
        optIdx = optind;

        char opt = getopt(argc, argv, "nt:");
        if (opt == -1)
            break;

        switch (opt)
        {
            case 'n':
                cout << "saw option " << opt << 
                        " optIdx = " << optIdx << //", optind = " << optind <<
                        '\n';
            break;

            case 't':
                cout << "saw option " << opt << ", value " << optarg << 
                        " optIdx = " << optIdx << //", optind = " << optind <<
                        '\n';

            break;

            default:
                cout << "saw undefined option " << 
                        " optIdx = " << optIdx << // ", optind = " << optind <<
                        '\n';
            break;
       }
    }

    cout << "\n"
            "optIdx = " << optIdx << ", optind = " << optind << 
            ", argc = " << argc << 
            // ", diff optind = " << (argc - optind) << 
            ", argv:\n";

    for (int idx = 0; idx != argc; ++idx)
        cout << "   " << idx << ": " << argv[idx] << '\n';

    cout << "\n\n";
}

//  a.out first -a -n -tx -t y one two
//  
// saw undefined option  optIdx = 1
// saw option n optIdx = 2
// saw option t, value x optIdx = 3
// saw option t, value y optIdx = 4
// 
// optIdx = 6, optind = 6, argc = 9, argv:
//    0: a.out
//    1: -a
//    2: -n
//    3: -tx
//    4: -t
//    5: y
//    6: first
//    7: one
//    8: two
// 


//  #include <getopt.h>
//  
//  int getopt_long(int argc, char *const *argv,
//             char const *optstring,
//             option const *longopts, int *longindex);
//
//  If longindex is not 0, it points to a variable which is set  to  the
//  index of the long option relative to longopts.

//  struct option                   // array of long options, final el.: 0
//  {
//      char const *name;
//      int         has_arg;        // no_argument, required_argument,
//                                  // optional_argument
//      int        *flag;           // = 0,
//      int         val;            // value to return (e.g. 
//                                  // the short option equiv.
//  };

