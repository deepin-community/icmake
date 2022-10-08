//#define XERR
#include "cpu.ih"

// This function is executed when an op_call_rss opcode is encountered in the
// .bim file. Following this opcode a function index is expected (an
// uint8_t value), indicating the function number to call (see the
// enumeration BuiltinFunction in the file
// support/builtinfunction/builtinfunction.h 
// 
// If the index exceeds or equals BuiltinSize, an error occurs. Otherwise, the
// indicated built in function is called (see the class Builtin)

// See stack/README for a description of how to interpret the indices: when
// calling functions use indices >= 2 to access arguments (the 1st function
// argument is at d_stack[2]), and use indices < 0 to access local variables
// (the 1st local variable is at d_stack[-1])

void CPU::callRss()
{
    size_t funIdx = d_hdr.get<uint8_t>();   // get the function's index

    xerr("call rss " << funIdx << ": " << BuiltinFunctions::name(funIdx));

    d_stack.push(Variable{});               // push a dummy RA

//    xerr("dummy pushed");

    d_stack.pushBP();

//    xerr("BP pushed");

    if (funIdx >= BuiltinFunctions::BuiltinSize)
        throw Exception{} << "invalid rss function call at offset " <<
                                                        (d_hdr.offset() - 2);

//    xerr("Calling " << funIdx);

    d_builtin.call(funIdx);                 // call the builtin function

//    xerr("Called " << funIdx);

    d_stack.popBP();

//    xerr("Popped BP");

    d_stack.pop();                          // remove the dummy RA

//    xerr("Popped dummy");

}




