//#define XERR
#include "generator.ih"

Generator::Generator(char const *bimName, Parser const &parser)
:
    d_bimName(bimName),
    d_bim(Exception::factory<ofstream>(bimName)),
    d_scanner(parser.scanner()),
    d_functions(parser.functions()),
    d_symtab(parser.symtab())
{
    xerr("");
}
