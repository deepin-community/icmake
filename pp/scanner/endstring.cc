#include "scanner.ih"

int Scanner::endString()
{
    begin(StartCondition_::INITIAL);
    return TEXT;
}
