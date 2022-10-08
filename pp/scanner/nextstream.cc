//#define XERR
#include "scanner.ih"

void Scanner::nextStream(string next)
{
    xerr(next << " at line " << lineNr());


                                    // remember where we came from and 
                                    // how many eolns were encountered
    d_streamData.push({ filesystem::current_path() });
    pushStream(next);               // then switch to the 'next' stream

                                    // as with flexc++: changed canonical to
                                    // absolute
    filesystem::path nextPath{ filesystem::absolute(next).remove_filename() };

    if (not Tools::changeDir(nextPath))
        throw fatal() << "cannot chdir to " << nextPath;
}
