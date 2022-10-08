#include "scanner.ih"

void Scanner::invalidString()
{
    error() << "double quote at end of string not found\n";
    begin(StartCondition_::INITIAL);
}
