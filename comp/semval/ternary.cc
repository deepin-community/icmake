//#define XERR
#include "semval.ih"

    // *this is the condition

SemVal SemVal::ternary(SemVal &&trueExpr, SemVal &&falseExpr) &&
{
    if ((trueExpr.type() & falseExpr.type() & e_mask) == e_null)
    {
        Error::msg(Error::TERNARY_TYPES) << "?:'\n";    // different types:
        return move(trueExpr);                          // error and return
    }                                                   // trueExpr

    if (d_type & e_const)
        return move(                                    // known
                (d_value == 0) and (d_type & e_int) ?   // false condition ->
                    falseExpr                           // return falseExpr
                :                                       // otherwise
                    trueExpr                            // return trueExpr
               );

    falseExpr.push();

    asBool();                                       // convert the condition 
                                                    // to bool-code 
    
    patchTrue(END);                                 // patch the true dest.
    trueExpr.push();                                // append the trueExpr
    *this << trueExpr;

    addPatchTrue(Opcode::jmp);                      // jmp around the false
                                                    // expr. 

    patchFalse(END);                                // patch the false dest
    falseExpr.push();
    *this << falseExpr;
    
                                // :? returns an expression, but is the
                                // patch already now necessary?

    patchTrue(END);                                 // patch the destination
                                                    // of the true-condition
    d_type = (trueExpr.type() & e_mask) | e_stack;

    return move(*this);
}
