#define XERR
#include "splitter.ih"

void Splitter::depOrDef()
{
    if (s_options[0].name == "dependencies"s)
        setAction();
}
