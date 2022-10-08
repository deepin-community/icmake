//#define XERR
#include "scanner.ih"

void Scanner::checkIdentRecursion() const
{
    size_t pos = 0;

    while (true)
    {
        pos = d_defineBuffer.find(d_ident, pos);

        if (pos == string::npos)
        {
            xerr("OK");
            return;                     // d_ident not found
        }

        if (identCharAt(pos - 1) or identCharAt(pos + d_ident.length()))
        {
            pos += d_ident.length();
            continue;
        }

        throw fatal() << '[' << pos << "] recursively defined #define " << 
                        d_ident << ": `" << d_defineBuffer << '\'';
    }
}
