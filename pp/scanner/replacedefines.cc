//#define XERR

// When a defined identifier is encountered then its name is replaced 
// by its value. elements in the definition may be enclosed by ${ and } in
// which case its content is checked for being a defined identifier. If so
// the ${...} part is replaced by its definition
//
// Caveat: a replaced definition is re-inserted into the input stream: when 
// a definition contains its own identifier it cannot be used because of
// unending recursion. replaceDefines's called (storeIdentValue) checks for
// this situation 

#include "scanner.ih"

void Scanner::replaceDefines()
{
    vector<size_t> dollars;             // positions of the $s in ${...}

    size_t count = 0;
    while (s_matchDefVar << d_defineBuffer)  // find ${xxx} elements
    {
        xerr("match: " << s_matchDefVar[3]);

        if (++count > s_maxReplacements)
            throw fatal() << d_defineBuffer << ": max. #replacements (" 
                                        << s_maxReplacements << ") exceeded";

                                                // first/beyond positions of
                                                // ${varname}
        auto matchPos = s_matchDefVar.position(2);

        size_t dollarIdx = matchPos.first;  // the index of the $:

        if (                                // if varname is a #defined name
            auto iter = d_symtab.find(s_matchDefVar[3]);
            iter != d_symtab.end()
        )                                   // then replace ${varname} by
            d_defineBuffer.replace(      // its value
                dollarIdx, matchPos.second - dollarIdx, iter->second
            );
        else                                // if not defined, then tempo.
        {                                   // remove the $:
            dollars.push_back(dollarIdx);
            d_defineBuffer[dollarIdx] = ' ';
        }
    }

    // restore the $s of ${name} of un-#defined name:
    for (size_t idx: dollars)
        d_defineBuffer[idx] = '$';
}
