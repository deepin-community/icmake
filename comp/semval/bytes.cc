#define XERR
#include "semval.ih"

void SemVal::bytes() const
{
    xerr("size code: " << d_code.size() << ", true: " << d_patchTrue.size() <<\
        ", false: " << d_patchFalse.size());
    cerr << "    " << hex << setfill('0');
    for (unsigned char ch: d_code)
        cerr << setw(2) << (unsigned)ch << ' ';
    cerr << dec << setfill(' ') << '\n';
}
