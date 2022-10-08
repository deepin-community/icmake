#ifndef INCLUDED_BUILTINFUNCTIONS_H_
#define INCLUDED_BUILTINFUNCTIONS_H_

#include <iosfwd>
#include <cstdint>
#include <cstddef>

                // recompile all files when a new builtin function is added
class BuiltinFunctions
{
    static char const *s_name[];
    static size_t s_nFunctions;

    public:
        enum Function
        {
            // 0
            ARG_HEAD,
            ARG_TAIL,
            ASCII_INT,                            // returns int
            ASCII_STR,                            // returns str
        
            // 4
            BACKTICK,                             
            C_BASE,
            C_EXT,
            C_PATH,
        
            // 8
            CHDIR,
            CMD_HEAD,
            CMD_TAIL,
            ECHO,
        
            // C
            LIST_ELEMENT,
            EVAL,
            EXEC,
            EXECUTE,                              // ONLY USED BY THE COMPILER
        
            // 10
            EXISTS,
            FGETS,
            FPRINTF,
            G_BASE,
        
            // 14
            G_DEXT,
            G_EXT,
            G_PATH,
            GETCH,
        
            // 18
            GETENV,
            GETPID,
            GETS,
            LISTLEN,
        
            // 1C
            MAKELIST,
            PRINTF,
            PUTENV,
            STAT,
        
            // 20
            STR_EL,
            STRFIND,
            STRFORMAT,
            STRLEN,
        
            // 24
            STRLWR,
            RESIZE,
            STRTOK,
            STRUPR,
        
            // 28
            SUBSTR,
            SYSTEM,
            TRIM,
            TRIMLEFT,
        
            // 2C
            TRIMRIGHT,
            STRCHR,
            LISTFIND,
            LISTUNION,
        
            // 30
            LISTCONST,
        
            BuiltinSize     // SIZE
        };


        static Function find(std::string const &name);  // BuiltinSize: 
                                                        // not builtin
        static char const *name(uint8_t index);
        static size_t nFunctions();
};

#include "name.f"
#include "nfunctions.f"

#endif
