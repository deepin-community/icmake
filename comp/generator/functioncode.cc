//#define XERR
#include "generator.ih"

void Generator::functionCode()
{
    d_bim.seekp(sizeof(Header));                // skip beyond the header

    d_bim << d_functions.code();

    d_header.firstOpcode = d_bim.tellp();       // first executed code byte
                                                // (1st byte beyond the code
                                                // of the functions: global
                                                // var. initialization and
                                                // calling main().
}
