//#define XERR
#include "unassembler.ih"

char const UnAssembler::s_0[] = "        ";
char const UnAssembler::s_1[] = "     ";
char const UnAssembler::s_2[] = "  ";

unordered_map<uint8_t, char const *> UnAssembler::s_typeName =
{
    { e_str,    "string"   },
    { e_int,    "int"      },
    { e_list,   "list"     },
};

UnAssembler::MaybeConst UnAssembler::s_disassemble[] =
{
    { .stable = &UnAssembler::jmp},             //     00
    { .stable = &UnAssembler::jmp_false},       //     01
    { .stable = &UnAssembler::jmp_true},        //     02
    { .stable = &UnAssembler::push_1_jmp_end},  //     03
    { .stable = &UnAssembler::push_0},          //     04
    { .stable = &UnAssembler::push_imm},        //     05
    { .stable = &UnAssembler::push_strconst},   //     06
    { .stable = &UnAssembler::push_var},        //     07
    { .stable = &UnAssembler::push_reg},        //     08
    { .stable = &UnAssembler::pop_var},         //     09
    { .stable = &UnAssembler::umin},            //     0a
    { .stable = &UnAssembler::atoi},            //     0b
    { .stable = &UnAssembler::itoa},            //     0c
    { .stable = &UnAssembler::atol},            //     0d
    { .stable = &UnAssembler::mul},             //     0e
    { .stable = &UnAssembler::div},             //     0f
    { .stable = &UnAssembler::mod},             //     10
    { .stable = &UnAssembler::add},             //     11
    { .stable = &UnAssembler::sub},             //     12
    { .stable = &UnAssembler::eq},              //     13
    { .stable = &UnAssembler::neq},             //     14
    { .stable = &UnAssembler::sm},              //     15
    { .stable = &UnAssembler::gr},              //     16
    { .stable = &UnAssembler::younger},         //     17
    { .stable = &UnAssembler::older},           //     18
    { .stable = &UnAssembler::smeq},            //     19
    { .stable = &UnAssembler::greq},            //     1a
    { .stable = &UnAssembler::call_rss},        //     1b
    { .stable = &UnAssembler::asp},             //     1c
    { .stable = &UnAssembler::exit},            //     1d
    { .stable = &UnAssembler::copy_var},        //     1e
    { .stable = &UnAssembler::inc},             //     1f
    { .stable = &UnAssembler::dec},             //     20
    { .stable = &UnAssembler::call},            //     21
    { .plain  = &UnAssembler::frame},           //     22
    { .stable = &UnAssembler::ret},             //     23
    { .stable = &UnAssembler::pop_reg},         //     24
    { .stable = &UnAssembler::band},            //     25
    { .stable = &UnAssembler::bor},             //     26
    { .stable = &UnAssembler::bnot},            //     27
    { .stable = &UnAssembler::bxor},            //     28
    { .stable = &UnAssembler::shl},             //     29
    { .stable = &UnAssembler::shr},             //     2a

    //   hlt                        //     2b
};


