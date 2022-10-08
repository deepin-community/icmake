//#define XERR
#include "scanner.ih"

    // filenames are either "name" or <name>. Name may be anything,
    // even nested separators, but can only be valid if such a filename
    // exists.

  
string Scanner::nextName(char sep0, char sep1)
{
    size_t begin = matched().find_first_of(sep0) + 1;

    return matched().substr(
                        begin,
                        matched().find_last_of(sep1) - begin
                    );
}

