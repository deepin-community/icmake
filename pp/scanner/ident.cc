//#define XERR
#include "scanner.ih"

int Scanner::ident()
{
    if (not d_active)
        return nTokens;                     // no action required

    xerr("matched: " << matched());

    string const &text = matched();

    auto iter = d_symtab.find(text);        // if a defined identifier, then
                                            // push its value, oterwise 
                                            // insert the identifier itself

//    xerr("identifier " << text << 
//            (iter == d_symtab.end() ? " not" : "") << " found");
    
    if (iter == d_symtab.end())             // not a defined name?
        return TEXT;                        // then insert the name

    push(iter->second);                 // or process the #defined name's
    return nTokens;                     // and lex() won't return
}



