#ifndef INCLUDED_STACK_
#define INCLUDED_STACK_

#include <cstdint>
#include <vector>
#include <string>

class Variable;             // the abstract base class for Ints, Strings,
                            // and Lists.

    // conceptually the stack grows from high to low, but the vector
    // grows from low to high. For pushing and popping that's irrelevant,
    // but when accessing a stack element based on its index the
    // sign of the index is negated.

class Stack
{
    std::string d_bimFilename;

    std::vector<Variable> d_stack;
    unsigned d_BP = 0;

    public:
        Stack(unsigned idx, unsigned argc, char **argv);

        Variable &operator[](int index);

        void push(Variable &&tmp);                      // 1
        void push(Variable const &var);                 // 2

        Variable topMove() noexcept;
        Variable &top();                                // .f
        void pop();                                     // .f

        void pushBP();
        void popBP();

        void asp(uint16_t nElements);                   // .f

    private:
        void pushCharPtrPtr(char **src);
        void pushArgs(unsigned idx, unsigned argc, char **argv);
};

#include "asp.f"
#include "pop.f"
#include "top.f"

#endif


