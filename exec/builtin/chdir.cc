//#define XERR
#include "builtin.ih"

// This function expects a string to change-dir to as second
// argument on the stack.  The stack top is the mode, 
// P_CHECK or P_NOCHECK.  
// 
// If the directory name is not empty, then the current working
// directory is set to the indicated path.  If the requested directory is an
// empty string, then a change-dir is performed to the startup directory.
// 
// Mode P_CHECK causes this function to abort upon failure.
// 
// The return register is set to the resulting working directory.

void Builtin::chdir()
{
    auto   mode = d_stack[2].value();
    string const &requestDir = d_stack[3].str();
    string dir = requestDir;

    if (dir.empty())
        dir = d_orgDir;

    error_code ec;
    dir = filesystem::absolute(dir, ec);        // abs. destination dir

    filesystem::current_path(dir, ec);          // change to the path

    dir = filesystem::current_path().string();  // obtain the cwd's path

    if (ec and mode == P_CHECK)         // chdir failed
            throw Exception{} << "can't chdir to `" << requestDir << '\'';

    if (dir.back() != '/')              // make sure there's a final /
        dir += '/';

    d_reg = move(dir);                  // assign the return register
}


