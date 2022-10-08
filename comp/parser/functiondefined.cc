#define XERR
#include "parser.ih"

void Parser::functionDefined(SemVal &body) 
{
    SemVal function = d_symtab.functionDefined(body);

    d_functions.add(function.code());

//xerr("DISASSEMBLING");
//d_unAssembler.disassemble(function.code());
}
