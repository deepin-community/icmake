#ifndef INCLUDED_CONSTANTS_
#define INCLUDED_CONSTANTS_

enum Constants
{
    OFF = 0,
    ON = 1,

    P_CHECK = 0,
    P_NOCHECK = 1,          // in fact: not P_CHECK

    O_FILE   = 1,          // see scanner/lexer
    O_DIR    = 2,
    O_SUBDIR = 4,
    O_ALL    = 8,

    IS_FILE   = 1,          // see scanner/lexer: same values as O_FILE etc.
    IS_DIR    = 2,
    IS_SUBDIR = 4,
    IS_ALL    = 8,

    IS_IFDIR  = 1,
    IS_IFCHR  = 2,
    IS_IFREG  = 4,
    IS_IREAD  = 8,
    IS_IWRITE = 16,
    IS_IEXEC  = 32,

    NORMAL_FILE     = 0x00,
    READONLY_FILE   = 0x01,
    HIDDEN_FILE     = 0x02,
    SYSTEM_FILE     = 0x04,
    VOLUME_ID       = 0x08,
    SUBDIR          = 0x10,
    ARCHIVED        = 0x20
};
        
#endif
