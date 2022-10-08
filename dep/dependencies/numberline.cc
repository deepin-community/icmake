//#define XERR
#include "dependencies.ih"

// static 
void Dependencies::numberLine(size_t count)
{
    for (size_t col = 1; col <= count; ++col)
        cout << setw(2) << col << ' ';

    cout.put('\n');
}
