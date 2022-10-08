//#define XERR
#include "semval.ih"

// see below for a description              

SemVal SemVal::ifStmnt(SemVal &cond, SemVal &trueStmnt, SemVal &falseStmnt)
{
    if (cond.type() & e_const)              // constant condition: use
    {                                       // trueStmnt or falseStmnt
        *this << (cond.boolConst() ? trueStmnt : falseStmnt);
        return move(*this);
    }

    bool useFalse = falseStmnt.d_code.size() != 0;

    cond.asBool();                          // prepare true- and false-lists

    if (trueStmnt.d_code.size() == 0)       // no trueStmnt 
    {
xerr("no true code");
        if (not useFalse)                   // and no falseStmnt:
{
xerr("no false code");
            return move(cond);              // then return cond as bool
}

xerr("false code");

        cond.patchFalse(END);               // only a falseStmnt: reach it

        *this << cond << falseStmnt;        // append the falseStmnt
        return *this;                       // and done
    }

xerr("true code");
    cond.patchTrue(END);                    // trueStmnt exists: reach it

    if (not useFalse)                       // no falseStmnt
    {
xerr("no false code");
        *this << cond << trueStmnt;         // append the trueStmnt
        return *this;                       // and done
    }
                  
xerr("false code");
                           
    trueStmnt.addPatchFalse(Opcode::jmp);   // add jmp around falseStmnt

        // trueStmnt's patchFalse list becomes cond's patchFalse list, 
        // so its jmp-locations must be incremented with cond's code size:
    trueStmnt.shiftPatchFalse(cond.d_code.length()); 

        // now save the trueStmnt's falselist (eventually becoming cond's
        // patchFalse list)
    auto patchFalse{ move(trueStmnt.d_patchFalse) }; 

        // append trueStmnt to cond: trueStmnt doesn't have a patchFalse list
        // anymore, so cond's patchFalse remains as-is
    cond << trueStmnt;

        // now that cond = cond | trueStmnt: cond's false jmps must reach
        // the end of cond's code:
    cond.patchFalse(END);

        // restore patchFalse as cond|falseStmnt's d_patchFalse:
    cond.d_patchFalse = move(patchFalse);
    
        // append (cond|trueStmnt)|falseStmnt to the initialization code:
    *this << cond << falseStmnt;

    return move(*this);    
}

// Aho, Sethi, Ullman, 1986, p. 505
// 
// S = if E then M1 S1
//     E.true  -> M1
//     S.next  -> merge(E.false, S1.next)
// 
// S = if E then M1 S1 N else M2 S2
//     E.true  -> M1
//     E.false -> M2
//     S.next  -> merge(S1.next, N.next, S2.next)
// 
//  -------------------------------------------------------------------------
//
//    The current object contains the if-stmnt's initialization list, so
//    the cond, trueStmnt and falseStmnt's code is appended to the current
//    object:
//
//    No trueStmnt, no falseStmnt:
//    ============================
//          F
//       +----->
//       |      
//    cond ---->
//          T   
//              
//    No trueStmnt:
//    =============
//          T
//       +--------------+------> T
//       |             T|
//    cond ---->  falseStmt ---> F
//          F
//
//    No falseStmnt:
//    ==============
//          F
//       +----------------+---> F
//       |               F|   
//    cond ---->  trueStmnt --> T
//          T     
//                
//    If-stmnt having a trueStmnt and a falseStmnt:
//          F
//       +---------------------------+
//       |                           |
//    cond ---->  trueStmnt | jmp    +----->  falseStmt -+--> F
//          T      T|    F|   |                   T|     |
//                  |     +---+--------------------------+
//                  |                              |
//                  +------------------------------+--------> T

