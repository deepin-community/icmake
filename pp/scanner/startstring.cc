#include "scanner.ih"

void Scanner::startString()
{
    more();
    begin(StartCondition_::string);
}

