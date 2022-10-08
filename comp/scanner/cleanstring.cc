#define XERR
#include "scanner.ih"

int Scanner::cleanString()
{
    string txt = matched();

    if (
        txt.front() == txt.back()               // surrounding chars are equal
        and                                     // and either ' or "
        "'\""s.find(txt.front()) != string::npos
    )
        txt = txt.substr(1, txt.length() - 2);  // then remove those chars

    setMatched( String::unescape(txt) );        // and unescape the returned
                                                // matched() string

    begin(StartCondition_::INITIAL);

    return Tokens::STRING;
}
