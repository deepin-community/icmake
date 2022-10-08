#ifndef INCLUDED_FRAME_
#define INCLUDED_FRAME_

// the stack grows from high SP values to low SP values. When a function
// is called its arguments are pushed in reversed order, followed by the
// function's return address. Then the current BP is pushed and BP is set to
// point to that location. The local variables take up 1 index position per
// variable. Arguments are reached as 'bp + index', where index value 2 refers
// to the function's 1st argument; Local variables are reached as 'bp - index'
// where index is negative (-1, -2, ...) and refers to the '-index'th local
// variable number. 
//  Here's the stack frame organization:
//
//          high stack offsets
//          |
//          |   arg#N           BP + N+1
//          |   ...
//          |   arg#2           BP + 3
//          |   arg#1           BP + 2
//          |   return
//    BP--> |   old BP
//          |   local#1         BP - 1
//          |   local#2         BP - 2
//          |   ...
//          |   local#N         BP - N
//          |
//    SP--> low stack offsets
//
//  The Frame class stores the types of the local variables in a vector:
//  its 1st element defines the type of the 1st local variable: access it
//  as element [-index - 1]

#include <cstdint>
#include <vector>

#include <iostream>

class BimHeader;

class Frame: private std::vector<uint8_t>
{
    BimHeader &d_hdr;

    public:
        Frame(BimHeader &hdr);
        uint8_t read();             // read the frame following a `frame'
                                    // opcode 

        uint8_t type(int16_t idx) const;
        using std::vector<uint8_t>::size; 
};

#include "type.f"
        
#endif
