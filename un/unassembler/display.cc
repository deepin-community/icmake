//#define XERR
#include "unassembler.ih"

// static
void UnAssembler::display(string const &str)
{
    cout.put('"');

    for (char ch: str)
        cout.put(isprint(ch) ? ch : '.');

    cout.put('"');
}
