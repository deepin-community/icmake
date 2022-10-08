//#define XERR
#include "cpu.ih"

void CPU::push0()
{
    d_stack.push( new Int{ 0 } );
}
