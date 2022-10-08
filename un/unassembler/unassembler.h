#ifndef INCLUDED_UNASSEMBLER_
#define INCLUDED_UNASSEMBLER_

#include <unordered_map>
#include <iosfwd>

#include "../frame/frame.h"

class BimHeader;

class UnAssembler
{
    enum VarType
    {
        GLOBAL,
        LOCAL,
        ARG,
    };

    BimHeader &d_hdr;
    mutable Frame d_frame;

    static char const s_0[];        // blanks after only an opcode
    static char const s_1[];        // blanks after an opcode + 1 byte arg.
    static char const s_2[];        // blanks after an opcode + 2 byte args.

    static std::unordered_map<uint8_t, char const *> s_typeName;

    union MaybeConst
    {
        void (UnAssembler::*stable)() const;
        void (UnAssembler::*plain)();
    };
    static MaybeConst s_disassemble[];

    static char const *s_funName[];
    static unsigned const s_nFunctions;

    public:
        UnAssembler(BimHeader &hdr);
        void run(std::string const &progname);

    private:
        void statistics() const;
        void varDump() const;
        void stringDump() const;

        void disassemble();             // disassemble the binary instructions
        void disassemble(uint16_t opCode) ;

        static void display(std::string const &str);    // stringDump strings
        static void display2(uint16_t  value);
        static void display4(uint16_t value);

        void handleVar(char const *instruction) const;

        static VarType varType(uint16_t *index);
        static void varValue(VarType type, int16_t idx);


        void jmp() const;             //     00
        void jmp_false() const;       //     01
        void jmp_true() const;        //     02
        void push_1_jmp_end() const;  //     03
        void push_0() const;          //     04
        void push_imm() const;        //     05
        void push_strconst() const;   //     06
        void push_var() const;        //     07
        void push_reg() const;        //     08
        void pop_var() const;         //     09
        void umin() const;            //     0a
        void atoi() const;            //     0b
        void itoa() const;            //     0c
        void atol() const;            //     0d
        void mul() const;             //     0e
        void div() const;             //     0f
        void mod() const;             //     10
        void add() const;             //     11
        void sub() const;             //     12
        void eq() const;              //     13
        void neq() const;             //     14
        void sm() const;              //     15
        void gr() const;              //     16
        void younger() const;         //     17
        void older() const;           //     18
        void smeq() const;            //     19
        void greq() const;            //     1a
        void call_rss() const;        //     1b
        void asp() const;             //     1c
        void exit() const;            //     1d
        void copy_var() const;        //     1e
        void inc() const;             //     1f
        void dec() const;             //     20
        void call() const;            //     21
        void frame();                 //     22
        void ret() const;             //     23
        void pop_reg() const;         //     24
        void band() const;            //     25
        void bor() const;             //     26
        void bnot() const;            //     27
        void bxor() const;            //     28
        void shl() const;             //     29
        void shr() const;             //     2a
};
        
#endif

