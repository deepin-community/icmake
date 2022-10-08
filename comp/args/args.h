#ifndef INCLUDED_ARGS_
#define INCLUDED_ARGS_

#include <vector>
#include "../semval/semval.h"
#include "../builtin/builtin.h"
#include "../functions/functions.h"

// see comment below

class Args: public std::vector<SemVal>
{
    public:
        Args() = default;

        Args(SemVal &semVal);                                           // 4.f
        Args(std::vector<SemVal> &semValVect);  // steals semValVect    // 5.f


        Args &add(SemVal &semVal);      // does push_back

                                        // if true then 'ret' calls 
                                        // builtin function 'name'
        bool builtin(SemVal &ret, std::string const &name);

        SemVal callBuiltin(Builtin::Function function);

                                        // if true then 'ret' calls 
                                        // user-defined function 'name'
        bool function(SemVal &ret, Functions::Overload const *overloads);

                                        // back() has the conditition code,
                                        // before that: var. initializations
        SemVal ifStmnt(SemVal &trueStmnt, SemVal &falseStmnt);
        SemVal forStmnt(SemVal &cond, Args &inc, SemVal &stmnt);

    private:
        uint8_t pushArgs(SemVal &ret);
        SemVal callMakelist();

                            // cannot be const members as an optional initial
                            // int value may be inserted
        bool typesMatch(Builtin::Function function);
        bool initialTypes(Builtin::Function function, 
                          Builtin::ArgsIter &funBegin, 
                          Builtin::ArgsIter funEnd,
                          unsigned &argBegin, unsigned argEnd);
        bool makelist(Builtin::ArgsIter funBegin, Builtin::ArgsIter funEnd,
                      unsigned argBegin, unsigned argEnd);
        bool trailingTypes(Builtin::ArgsIter funBegin, 
                           Builtin::ArgsIter funEnd,
                           unsigned argBegin, unsigned argEnd) const;

                                        // used for builtin functions   (1.f)
        bool equalTypes(Builtin::ArgsIter funIter, unsigned argIdx) const;

                                        // used when calling functions  (2.cc)
        bool equalTypes(std::vector<ExprType> const &paramTypes) const;

        bool callFunction(SemVal &ret, Functions::Info const &info);

        SemVal catExpressions(unsigned end);    // push the code of 
                                        // initialization, init and inc
};
        
#include "args4.f"
#include "args5.f"

// the structure of arguments passed to functions is:
// 
// The SemVal argument structure:
// 
//   SemVal
//   [
//       type:   
//       value:  #arguments
//       code:   [ ... 'value' SemVal structs ... ]
//                |              |              |
//                |              |              +-> the last SemVal refers to
//                |              |                  the last argument
//                |              |           
//                |              +-> each SemVal has code pushing an argument
//                |                  on the run-time (icm-exec) stack
//                |                  (i.e., executable code)
//                |
//                +-> the 1st SemVal refers to 
//                    the first argument
//   ]


#endif
