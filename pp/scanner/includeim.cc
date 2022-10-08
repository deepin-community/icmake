//#define XERR
#include "scanner.ih"

bool Scanner::includeIM()
{
    if (not d_active)
        return false;

    string next = nextName('<', '>');

    char const *im;
    if (im = getenv("IM"); im == 0)             // no IM env. var
        throw fatal() << "IM environment variable not defined";
    
    for (auto const &pair: String::split(im, String::TOK, ":"))
    {
        string fullName{ pair.first + '/' + next };

        xerr("fullname: " << fullName);

        if (Tools::exists(fullName))
        {
            nextStream(fullName);
            return true;
        }
    }

    throw fatal() << "can't find `" << next << 
                        "' in IM directories (" << im << ')';
}

