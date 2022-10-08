//#define XERR
#include "scanner.ih"

void Scanner::setLineNr()
{
    d_input->setLineNr(stoul(matched().substr(1)));
    setWhere();
xerr(" continue at line  " << lineNr());
}
