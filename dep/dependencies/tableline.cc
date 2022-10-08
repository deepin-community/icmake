//#define XERR
#include "dependencies.ih"

// static
void Dependencies::tableLine(size_t nBlanks, size_t width)
{
    if (nBlanks)
        cout << setw(nBlanks) << ' ';

    if (width)
        cout << setfill('-') << setw(width) << '-' << setfill(' ');

    cout.put('\n');
}
