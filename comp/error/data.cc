//#define XERR
#include "error.ih"

size_t Error::s_nErrors = 0;
size_t Error::s_error = 0;
size_t Error::s_lastLine = 0;
size_t Error::s_displayCount = 0;

char const *Error::s_static[] =
{
    ""                                          ,   // OFF,         (( <- matching below
    "')' expected"                              ,   // CLOSEPAREN,             
    "',' or ')' expected"                       ,   // COMMA_OR_CLOSEPAREN,    
    "',' or ';' expected"                       ,   // COMMA_OR_SEMICOL,       
    "error in expression"                       ,   // EXPRESSION,             
    "identifier expected"                       ,   // IDENTIFIER,             
    "error in initialization"                   ,   // INIT,                   
    "function `main' not defined"               ,   // NO_MAIN,               
    "'(' expected"                              ,   // OPENPAREN,  ) <- for matching
    "'{' expected"                              ,   // OPENCURLY,  } <- for matching
    "';' expected"                              ,   // SEMICOL,    
    "error in statement"                        ,   // STATEMENT,             
    "typename/void expected"                    ,   // TYPENAME,   
};

char const *Error::s_semantic[] =
{
    "", // NO_ERROR
    "ambiguous overload for `"                                      ,   // AMBIGUOUS_OVERLOAD,    
    "incorrect number and/or types of arguments for `"              ,   // ARGUMENT_MISMATCH,     
//    "cannot overload `"                                             ,   // CANNOT_OVERLOAD,       
    "division by zero for operator `"                               ,   // DIVISION_BY_ZERO,      
    "invalid argument type for `exit': expected: int, got: "        ,   // EXIT_TYPE,             
    "`fprintf <<' must first insert a string\n"                     ,   // FPRINTF_NO_STR,        
    "index operators require `string[int]' or `list[int]'\n"        ,   // INDEX_TYPE,            
    "invalid cast from `"                                           ,   // INVALID_CAST,          
    "invalid operand for `"                                         ,   // INVALID_OPERAND,       
    "list constant arguments must be (convertible to) string\n"     ,   // LIST_CONST,                      +
    "lexpr needed for `"                                            ,   // LVALUE_NEEDED,                   +
    "main(): cannot be called recursively\n"                        ,   // MAIN_NOT_RECURSIVE,    
    "main(): cannot be overloaded\n"                                ,   // MAIN_NO_OVERLOADS,
    "main(): parameters must be ([int [,list [,list]]])\n"          ,   // MAIN_PARAMS_ERROR,     
    "main(): return type must be `void' or 'int'\n"                 ,   // MAIN_RETURN_ERROR,     
    "multiply defined: `"                                           ,   // MULTIPLY_DEFINED,                +
    "(f)printf cannot be nested in (f)printf insertions\n"          ,   // NESTED_PRINTF_INSERTION
    "`break': only in `while' and `for' statements\n"               ,   // NO_BREAK,              
    "`continue: only in `while' and `for' statements\n"             ,   // NO_CONTINUE,           
    "different operand types of `"                                  ,   // OPERAND_TYPES,
    "(f)printf needs shl-operator (<<)\n"                           ,   // PRINTF_OPCODE
    "return type error for function `"                              ,   // RETURN_TYPE,           
    "the ternary operator's expr2 and expr3 types must be equal\n"  ,   // TERNARY_TYPES,         
    "variable not defined: `"                                       ,   // UNDEFINED_VAR,                   +     
    "function not defined: `"                                       ,   // UNDEFINED_FUNCTION,    
};
