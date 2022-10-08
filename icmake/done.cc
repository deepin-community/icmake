#define XERR
#include "main.ih"

bool done(char const *program, Splitter::Action action)
{
    switch (action)
    {
        case Splitter::ABOUT:
            about(program);
        break;

        case Splitter::HELP:
            usage(program);
        break;

        case Splitter::VERS:
            version(program);
        break;

        default:
        return false;
    }

    return true;
}
