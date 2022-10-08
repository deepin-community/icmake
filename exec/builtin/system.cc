//#define XERR
#include "builtin.ih"

void Builtin::system()
{
    string const &cmd = d_stack[3].str();       // get the cmd

                                                // prepare for its execution
    Process process{ Process::NONE, Process::USE_SHELL, cmd };      
                                                
//    process.system();
//    cout << "\n"
//            "DONE: process `" << cmd << "' returns " << 
//            process.waitForChild() << endl;

    execute(d_stack[2].value() == P_CHECK, "system", 
            process, &Process::system);
}
