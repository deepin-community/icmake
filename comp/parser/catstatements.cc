//#define XERR
#include "parser.ih"

// static
SemVal Parser::catStatements(SemVal &stmnts, SemVal &stmnt) 
{
    stmnts.catStatement(stmnt);
    return move(stmnts);
}
