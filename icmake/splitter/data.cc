//#define XERR
#include "splitter.ih"

// static
char Splitter::s_empty[] = { 0 };

// static                       // chars must follow Action's ordering
string Splitter::s_xlat{ "cdefpstu" "ahv" };  

// static
option Splitter::s_options[] =
{
    { "dependencies",       no_argument, 0, 'd' },
    { "about",              no_argument, 0, 'a' },
    { "compile",            no_argument, 0, 'c' },
    { "execute",            no_argument, 0, 'e' },
    { "force",              no_argument, 0, 'f' },
    { "help",               no_argument, 0, 'h' },
    { "no-version-check",   no_argument, 0, 'n' },
    { "no-process",         no_argument, 0, 'N' },
    { "preprocess",         no_argument, 0, 'p' },
    { "source",             no_argument, 0, 's' },
    { "tmpdir",             required_argument, 0, 'T' },
    { "unassemble",         no_argument, 0, 'u' },
    { "verbose",            no_argument, 0, 'V' },
    { "version",            no_argument, 0, 'v' },
    { 0 }
};

