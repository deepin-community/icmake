//#define XERR
#include "scanner.ih"

bool Scanner::identCharAt(int pos) const
{
    return 
        (pos == -1 or static_cast<size_t>(pos) 
                      == d_defineBuffer.length()) ? // no ident char if at
            false                                   // the buffer's ends
        :
            isalnum(d_defineBuffer[pos]) or d_defineBuffer[pos] == '_';
}
