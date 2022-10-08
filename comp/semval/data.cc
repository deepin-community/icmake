//#define XERR
#include "semval.ih"

//SemVal &(SemVal::*SemVal::s_insert1)(uint8_t opcode) = &SemVal::insert1;
//SemVal &(SemVal::*SemVal::s_insert2)(short value) = &SemVal::insert2;
//SemVal &(SemVal::*SemVal::s_insert3)(SemVal &rhs) = &SemVal::insert3;

Opcode::Byte SemVal::s_lastOpcode = Opcode::invalid;    

vector<bool> SemVal::s_deadCode(1);

bool SemVal::s_returns;
