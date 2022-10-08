#ifndef INCLUDED_EXPRTYPE_ENUM_H_
#define INCLUDED_EXPRTYPE_ENUM_H_

enum ExprType
{
    e_null          = 0,
    e_void          = 0,

    // rss + compiler: 
    e_int           = (1 << 0),     // 1: int-type    expression 
    e_str           = (1 << 1),     // 2: string-type expression 
    e_list          = (1 << 2),     // 4: list-type   expression 

    // compiler only: 
    e_bool          = (1 << 3),     // 8: bool-type   expression 
                                    // also: main() not yet defined

    e_intMask       = e_int | e_bool,

    e_mask          = (e_int | e_list | e_str | e_bool),

        // result type (set by icm-comp SemVal::setResult)
    e_const         = (1 << 4),     // 0x10 immediate value 
    e_var           = (1 << 5),     // 0x20 variable (accepting assignment)
    e_reg           = (1 << 6),     // 0x40 (return values from functions)
    e_stack         = (1 << 7),     // 0x80 (tmp) value available on the stack 

    e_prefix        = (1 << 8),     // pre-inc or pre-dec        
    e_postfix       = (1 << 9),     // post-inc or post-dec

    e_order         = (1 << 10),    // parser/inc/args: older, younger

    e_printf        = (1 << 11),    // parser/semval: printf calls
    e_fprintf       = (1 << 12),    // used for 'printf <<' expreessions

    e_printMask     = e_printf | e_fprintf,
};

#endif
