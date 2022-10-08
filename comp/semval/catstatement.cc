//#define XERR
#include "semval.ih"

void SemVal::catStatement(SemVal &next)
{
    xerr("stack size: " << s_deadCode.size());

    if (not s_deadCode.back())
    {
        patchFalse(END);
        patchTrue(END);

        *this << next;

        s_deadCode.back() = (d_state = next.d_state) != ACCEPT;
        s_returns = (d_state & RETURN) != 0;
    }

    xerr("OUT");
}
