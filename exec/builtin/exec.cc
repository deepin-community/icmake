//#define XERR
#include "builtin.ih"

//  This function is called to execute a command, (PATH is used). The stack 
//  contains:
//
//      stack[2]:   the total number of arguments of the exec() statement.
//                  including the execution mode and the command (so, if
//                  1 argument is provided, stack[2] == 3.
//      stack[3]:   the execution mode (P_(NO)CHECK)
//      stack[4]:   the command to execute
//      stack[5..]: any additional arguments

void Builtin::exec()
{

    Process process{ Process::NONE, 
                     Process::USE_SHELL,
                     d_stack[4].str() };       // the cmd to execute

                                                // add the arguments
    for (
        size_t idx = 5, end = idx + d_stack[2].value() - 2; 
            idx != end; 
                ++idx)
        process += ' ' + d_stack[idx].to_string();

                                                // assigns d_ret
    execute(d_stack[3].value() == P_CHECK, "executing", 
            process, &Process::start);
}




