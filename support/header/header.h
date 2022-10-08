#ifndef INCLUDED_HEADER_H_
#define INCLUDED_HEADER_H_

#include <cstdint>

struct Header
{
    char version[4];
    uint32_t strings;       // offset of the string constant-area
    uint32_t variables;     // offset of the variable area
    uint32_t filenames;     // offset of the strings area
    uint32_t firstOpcode;   // offset of the first instruction to execute
};


#endif
