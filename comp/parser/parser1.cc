//#define XERR
#include "parser.ih"

Parser::Parser(char const *input)
:
    d_scanner(input, "-"),
    d_symtab(d_functions)
//    d_unAssembler(d_symtab)
{}
