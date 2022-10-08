//#define XERR
#include "scanner.ih"

Scanner::Token Scanner::storeIdentValue()
{
    xerr("");

    begin(StartCondition_::INITIAL);

    if (d_active)
    {
        replaceDefines();

        checkIdentRecursion();

        d_symtab[d_ident] = String::trim(d_defineBuffer); 
    }

    return NL;
}

