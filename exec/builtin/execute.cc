//#define XERR
#include "builtin.ih"

void Builtin::execute(bool check, char const *label,
                      Process &process, void (Process::*member)() )
{
    if (d_echo)
        cout << process.str() << endl;

    (process.*member)();                        // execute the command (using
                                                // start or system)

    int ret = process.waitForChild();           // get the return value

    if (check and ret != 0)                     // on failure...
        throw Exception{} << label << " `" << process.str() << 
                            "' failed. Exit value = " << ret << '\n';

    d_reg = ret;
}
