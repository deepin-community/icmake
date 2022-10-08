#include "scanner.ih"

void Scanner::endifDirective()
{
    if (d_nest.empty())
        error() << "#endif without matching #if\n";
    else
    {
        d_active = d_nest.top();        // return to the previous activation
        d_nest.pop();                   // level
    }
}
