#ifndef INCLUDED_LOG_
#define INCLUDED_LOG_

#include <bobcat/log>
#include <bobcat/level>

enum LogLevel
{
    V0 = 4,         // initially no messages
    V1 = 3,         // -V specified: basic level
    V2 = 2,         // -VV specified
    V3 = 1,         // -VVV specified
    V4 = 0,         // -VVVV specified (most elaborate)
};

extern FBB::Log g_log;

#endif
