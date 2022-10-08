//#define XERR
#include "scanner.ih"

Scanner::Scanner()
:
    ScannerBase(cin, cout)
{
    defineOptions();

    setFiles();             // switch files if args were specified
}

