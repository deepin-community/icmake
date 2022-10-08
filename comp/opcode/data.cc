//#define XERR
#include "opcode.ih"

ExprType Opcode::s_types[] = 
{
//  allowed types                  opcode           hex value
    e_null,                     // jmp,             00
    e_null,                     // jmp_false,       01
    e_null,                     // jmp_true,        02
    e_null,                     // push_1_jmp_end,  03
    e_null,                     // push_0,          04
    e_null,                     // push_imm,        05
    e_null,                     // push_strconst,   06
    e_null,                     // push_var,        07
    e_null,                     // push_reg,        08
    e_null,                     // pop_var,         09
    e_int | e_list | e_bool,    // umin,            0a
    e_str,                      // atoi,            0b
    e_int | e_bool,             // itoa,            0c
    e_str,                      // atol,            0d
    e_int | e_bool,             // mul,             0e
    e_int | e_bool,             // div,             0f
    e_int | e_bool,             // mod,             10
    e_mask,                     // add,             11
    e_int | e_list,             // sub,             12
    e_mask,                     // eq,              13
    e_mask,                     // neq,             14
    e_int | e_bool | e_str,     // sm,              15
    e_int | e_bool | e_str,     // gr,              16
    e_str,                      // younger,         17
    e_str,                      // older,           18
    e_int | e_bool | e_str,     // smeq,            19
    e_int | e_bool | e_str,     // greq,            1a
    e_null,                     // call             1b
    e_null,                     // asp              1c
    e_null,                     // ret              1d
    e_null,                     // copy_var         1e
    e_int,                      // inc              1f
    e_int,                      // dec              20
    e_null,                     // call             21
    e_null,                     // frame            22
    e_null,                     // ret              23
    e_null,                     // pop_             24
    e_int,                      // band             25
    e_int,                      // bor              26
    e_int,                      // bnot             27
    e_int,                      // xor              28
    e_int,                      // shl              29
    e_int,                      // shr              2a
    e_null,                     // invalid          2b
};
