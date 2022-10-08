//#define XERR
#include "stack.ih"

// /usr/lib/icmake/icm-exec /tmp/15632.bim 
//  0                        1               # = 2
//                           0               # = 1

Stack::Stack(unsigned idx, unsigned argc, char **argv)
{
    d_bimFilename = argv[idx];

    pushCharPtrPtr(environ);
    pushArgs(idx, argc, argv);

    push(new Int{ as<int>(argc - idx) }); // 4 for 'bim a b c'
}



