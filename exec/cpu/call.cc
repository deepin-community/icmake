//#define XERR
#include "cpu.ih"

void CPU::call()
{
    auto offset = d_hdr.get<uint16_t>();    // the address of the fun to call
                                            // (in the .bim file, so wrt its
                                            // beginning
    xerr("call function at " << offset);
                                   
                                            // push the called function's RA   
    d_stack.push( new Int{ as<int>(d_hdr.offset()) } );
    xerr("RA is " << d_hdr.offset());

    d_stack.pushBP();                       // save the BP, set it to the
                                            // current SP
                        
    d_hdr.seekg(offset);                // continue at the function's address
}
