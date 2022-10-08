#define XERR
#include "semval.ih"

//  '*this' contains the code of the init-section
//  when used as 'while' the init-section is empty

//  the stmnt beyond 'init' is constructed in 'cond'. 
//  '|' in comment indicates catenation of SemVal code blocks

SemVal SemVal::forStmnt(SemVal &cond, SemVal &inc, SemVal &stmnt)
{
    if (not (cond.d_type & e_const))        // 'cond' is not constant
        cond.asBool();                      // -> prepare T/F lists
    else if (not cond.boolConst())          // cond is constant but false: 
        return move(*this);                 // merely return init

                                            // save the patches to the 
                                            // stmnt's end
    vector<unsigned> condFalse = move(cond.d_patchFalse);

    if (not (stmnt.d_type & e_const))       // stmnt has code
    {
        cond.patchTrue(END);                // continue at stmnt
        cond << stmnt;                      // cond is 'cond | stmnt'
    
                                            // no inc, then continue at 
                                            // cond's begin
        PatchDest patchDest = inc.d_type & e_const ? BEGIN : END;

        cond.patchTrue(patchDest);          // stmnt continues at Inc
        cond.patchFalse(patchDest);         // or (if Inc constant)
        cond.patchContinue(patchDest);      // at cond's 1st opcode byte
                                            
        merge(condFalse, cond.d_patchBreak);// add stmnt's break jumps
    }

    if (not (inc.d_type & e_const))         // inc has code
        cond << inc;

    cond.addPatchTrue(Opcode::jmp);         // jump to the code-begin

    cond.patchTrue(BEGIN);                  // continue at cond's begin

    cond.d_patchFalse = move(condFalse);    // restore cond's False- (and
                                            // stmnt's Break) exits
    *this << cond;                          // append to init

    return move(*this);
}


//  Init:   initialization is available as (*this) stmnt
//
//  -:      constant element
//  c:      element has code
//  |:      cat stmnt
//
//Cond    Stmnt    Inc      code:
//-------------------------------------------------------------------
//
//  F       ?       ?       Init
//
//  T       -       -       Init | ---+         
//                                 ^  |
//                                 |  |
//                                 +--+
//
//  
//  T       -       c       Init |    Inc -+
//                                 ^       |
//                                 |       |
//                                 +-------+
//
//
//  T       c       -                          br
//                          Init |    Stmnt -+---------->
//                                 ^         |
//                                 |         | T,F,cont
//                                 +---------+
//
//
//  T       c       c                   +-------------------->
//                                    br|
//                        Init | -- Stmnt ---------- Inc -+
//                               ^        T,F,cont        |
//                               |                        |
//                               +------------------------+
//
//
//  c       -       c                   F--------->
//                                      |
//                        Init |  Cond -+
//                               ^      |
//                               |      T-> Inc -+
//                               |               |  
//                               |               |    
//                               +---------------+
//
//
//  c       c       -                   F-------+------------>
//                                      |       |
//                        Init |  Cond -+       |
//                               ^      |     br|   
//                               |      T-> Stmnt -+          
//                               |                 |T,F,cont 
//                               |                 |
//                               +-----------------+
//
//
//  c       c       c                   F-------+-------------------->
//                                      |       |
//                        Init |  Cond -+       |
//                               ^      |     br|
//                               |      T-> Stmnt ----------> Inc -+
//                               |                T,F,cont         |
//                               |                                 |
//                               +---------------------------------+
