#include "scanner.ih"

void Scanner::elseDirective()
{
    if (d_nest.empty())
        error() << "#else without matching #if\n";

    else if (d_nest.top())              // previous level active,
        d_active = not d_active;        // else toggle the activation level
}
