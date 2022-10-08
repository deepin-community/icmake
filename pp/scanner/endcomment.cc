#include "scanner.ih"

int Scanner::endComment()
{
    begin(StartCondition_::INITIAL);
    return SPACE;
}
