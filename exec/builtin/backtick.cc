//#define XERR
#include "builtin.ih"

// This function expects a string specifying an executable command as argument
// value. The command is executed by system(). The standard output produced by
// the call is returned as a list, one element per output line. If the list is
// empty the command has failed. A command not producing any output at least
// results in a list having one (empty) string.

void Builtin::backtick()
{
    string const &cmd = d_stack[2].str();       // get the cmd

                                                // prepare for its execution
    Process process{ Process::COUT | Process::IGNORE_CERR, 
                     Process::USE_SHELL, cmd };

    if (d_echo)
        cout << process.str() << endl;

    process.start();

    vector<string> lines;
    string line;
    while (getline(process, line))
    {
        xerr(line);
        if (not process.eof())
            line += '\n';

        lines.push_back(move(line));
    }

    int ret = process.waitForChild();
    xerr("exit: " << ret);

    if (ret != 0)
        lines.clear();
    else if (lines.empty())
        lines.push_back(string{});

    d_reg = move(lines);
}



