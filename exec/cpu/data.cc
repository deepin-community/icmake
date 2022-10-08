//#define XERR
#include "cpu.ih"

void (CPU::*CPU::s_execute[])() =
{
    &CPU::jmp,             //     00
    &CPU::jmpFalse,        //     01
    &CPU::jmpTrue,         //     02
    &CPU::push1jmpEnd,     //     03
    &CPU::push0,           //     04
    &CPU::pushImm,         //     05
    &CPU::pushStrConst,    //     06
    &CPU::pushVar,         //     07
    &CPU::pushReg,         //     08
    &CPU::popVar,          //     09
    &CPU::umin,            //     0a
    &CPU::atoi,            //     0b
    &CPU::itoa,            //     0c
    &CPU::atol,            //     0d
    &CPU::mul,             //     0e
    &CPU::div,             //     0f
    &CPU::mod,             //     10
    &CPU::add,             //     11
    &CPU::sub,             //     12
    &CPU::eq,              //     13
    &CPU::neq,             //     14
    &CPU::sm,              //     15
    &CPU::gr,              //     16
    &CPU::younger,         //     17
    &CPU::older,           //     18
    &CPU::smeq,            //     19
    &CPU::greq,            //     1a
    &CPU::callRss,         //     1b
    &CPU::asp,             //     1c
    &CPU::nc<&CPU::exit>,  //     1d       const
    &CPU::copyVar,         //     1e
    &CPU::inc,             //     1f
    &CPU::dec,             //     20
    &CPU::call,            //     21
    &CPU::frame,           //     22
    &CPU::ret,             //     23
    &CPU::popReg,          //     24
    &CPU::band,            //     25
    &CPU::bor,             //     26
    &CPU::bnot,            //     27
    &CPU::bxor,            //     28
    &CPU::shl,             //     29
    &CPU::shr,             //     2a
};
