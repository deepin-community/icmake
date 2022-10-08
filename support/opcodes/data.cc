//#define XERR
#include "opcodes.ih"

char const *Opcodes::s_mnemonic[] = 
{
    "jmp",              //     00
    "jmp_false",        //     01
    "jmp_true",         //     02
    "push_1_jmp_end",   //     03
    "push_0",           //     04
    "push_imm",         //     05
    "push_strconst",    //     06
    "push_var",         //     07
    "push_reg",         //     08
    "pop_var",          //     09
    "umin",             //     0a
    "atoi",             //     0b
    "itoa",             //     0c
    "atol",             //     0d
    "mul",              //     0e
    "div",              //     0f
    "mod",              //     10
    "add",              //     11
    "sub",              //     12
    "eq",               //     13
    "neq",              //     14
    "sm",               //     15
    "gr",               //     16
    "younger",          //     17
    "older",            //     18
    "smeq",             //     19
    "greq",             //     1a
    "call_rss",         //     1b
    "asp",              //     1c
    "exit",             //     1d
    "copy_var",         //     1e
    "inc",              //     1f
    "dec",              //     20
    "call",             //     21
    "frame",            //     22
    "ret",              //     23
    "pop_reg",          //     24
    "band",             //     25
    "bor",              //     26
    "bnot",             //     27
    "bxor",             //     28
    "shl",              //     29
    "shr",              //     2a
    "invalid",          //     2b
};
