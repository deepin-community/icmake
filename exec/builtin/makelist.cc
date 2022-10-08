#define XERR
#include "builtin.ih"

//      This function converts the last pushed string into a listvariable
//      holding expanded filenames. On return d_reg contains the 
//      (alphabetically, case-sensitively sorted) list. 
//
//  The stack is organized as follows:
//
//  1: without older/younger
//
//      stack[2]   : Opcode::hlt
//      stack[3]   : filemask value (file type)
//      stack[4]   : pattern
//
//  2: with older/younger
//
//      stack[2]   : Opcode::older or Opcode::younger
//      stack[3]   : filemask value
//      stack[4]   : pattern
//      stack[5]   : reference filename
//
//  filemask values:    O_ALL,  O_DIR,      O_FILE,         O_SUBDIR
//  Glob Type:          ANY,    DIRECTORY,  REGULAR_FILE,   DIRECTORY
//  Glob Flags:         PERIOD  PERIOD      PERIOD
//                      NOMATCH NOMATCH     NOMATCH         NOMATCH

void Builtin::makeList()
{
    Opcodes::Byte selector = as<Opcodes::Byte>(d_stack[2].value());

    vector<string> ret;
    switch (selector)
    {
        case Opcodes::younger:
            ret = youngerList();
        break;

        case Opcodes::older:
            ret = olderList();
        break;

        default:
            ret = patternList();
        break;
    }

    d_reg = move(ret);
}







