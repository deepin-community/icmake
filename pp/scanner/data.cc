#include "scanner.ih"


                           //    directive         ident: [1]
Pattern Scanner::s_matchIdent{ "#\\w+"   "\\s+"  "(\\S+)" };

                              //    directive
Pattern Scanner::s_matchDirective{ "#\\S+"   };

                            //                           [3] is the var.name
                            //   no \              ${     defVar         }
Pattern Scanner::s_matchDefVar{ "([^\\\\]|^)"  "(\\$\\{" "((\\w|_)+)" "\\})" };
//                               1              2         34

char const *Scanner::s_tokenName[] =
{
    "ALL_DONE",
    "SPACE",
    "TEXT",
    "NL",
    "NEXT",
    "AT_EOF",
};

//////////////////


//                         // update if enum Directive (scanner.h) changes
// Scanner::Token (Scanner::*Scanner::s_startDirective[])() =
// {
//     &Scanner::ignore,
//     &Scanner::define,
// };

    // Following #define [1] is the defined word, [3] is the rest.
    // after matching, remove the //... comment from [3] 

                              //        1     2    3
//Pattern Scanner::s_directive{ "#\\w+\\s+(\\S+)(\\s+(.*)?)?" };
