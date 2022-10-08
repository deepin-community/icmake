//#define XERR
#include "parser.ih"

void Parser::functionHead()
{
    d_symtab.functionParams();
    d_breakOK = 0;
};
