#define XERR
#include "semval.ih"

    // see README.patch

SemVal &SemVal::insert3(SemVal &rhs)
{
    unsigned length = d_code.length();      // current code length

    d_code += rhs.d_code;                   // append rhs's code
    d_lastOpcode = rhs.d_lastOpcode;        // and update the last opocde

                                            // append rhs patch offsets +
                                            // length to d_patchTrue
    extend(d_patchTrue,     rhs.d_patchTrue,     length);
    extend(d_patchFalse,    rhs.d_patchFalse,    length);
    extend(d_patchBreak,    rhs.d_patchBreak,    length);
    extend(d_patchContinue, rhs.d_patchContinue, length);

    return *this;
}



