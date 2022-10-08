#define XERR
#include "args.ih"

// see below for the argument handling procedure

SemVal Args::callMakelist()
{
    SemVal ret;

    vector<unsigned> indices{ 3, 1, 0, 2 };

    if (size() == 4)            // comparison provided: turn into int const
        (*this)[2].setType(e_int | e_const);
    else                        // no comparison, provide Opcode::hlt
    {
        push_back(SemVal{ e_int | e_const, Opcode::hlt });
        indices.erase(indices.begin());
    }

    vector<SemVal> &args = *this;

                                    // 'indices' specifies the pusing order
    for (unsigned idx: indices)     // of the arguments
    {
        args[idx].push();
        ret << args[idx];
    }

    ret << Opcode::call_rss << as<uint8_t>(Builtin::MAKELIST) << 
           Opcode::asp << as<uint8_t>(size());

    ret.setResult(Builtin::returnType(Builtin::MAKELIST));

    return ret;
}

//  There are always 2 or 4 arguments: 4 argument: comparison string is used
//  With 2 args: a 3rd Opcode::hlt arg is added 
//
//  Arguments vector with 2 (-> 3) arguments:
//   [0]: selection type (e.g., O_FILE)
//   [1]: regex
//   [2]: hlt
//
//  Arguments vector with 4 arguments:
//   [0]: selection type (e.g., O_FILE)
//   [1]: regex
//   [2]: older/younger
//   [3]: comparison string

//      

//
//  argument:     0       1       2       3
//     makelist(O_ALL, "*.cc", younger, "xx");    
// 
//  [0014] 06 05 00   push string "xx"
//  [0017] 06 00 00   push string "*.cc"
//  [001a] 05 08 00   push int 0008
//  [001d] 05 17 00   push int 0017
//  [0020] 1b 1c      callrss 1c (makelist)
// 
//     makelist("*.cc", younger, "xx");    
// 
//  [0014] 06 05 00   push string "xx"
//  [0017] 06 00 00   push string "*.cc"
//  [001a] 05 01 00   push int 0001
//  [001d] 05 17 00   push int 0017
//  [0020] 1b 1c      callrss 1c (makelist)
// 
//     makelist("*.cc");    
// 
//  [0014] 06 00 00   push string "*.cc"
//  [0017] 05 01 00   push int 0001
//  [001a] 05 34 00   push int 0034
//  [001d] 1b 1c      callrss 1c (makelist)
// 
//     makelist(O_ALL, "*.cc");    
// 
//  [0014] 06 00 00   push string "*.cc"
//  [0017] 05 01 00   push int 0001
//  [001a] 05 34 00   push int 0034
//  [001d] 1b 1c      callrss 1c (makelist)
// 
// 1st pushed: comparison string or omitted
// 2nd pushed: regex
// 3rd pushed: selection type (O_FILE, O_ALL, ...)
// 4th pushed: greater, smaller (when comp. file is used), hlt (otherwise)
