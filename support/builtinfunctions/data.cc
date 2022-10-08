#include "builtinfunctions.ih"

char const *BuiltinFunctions::s_name[] =
{
        // 0
        "arghead",
        "argtail",
        "ascii_str2int",
        "ascii_int2str",

        // 4
        " backtick",        // added space to allow 'backtick' function names
        "change_base",
        "change_ext",
        "change_path",

        // 8
        "chdir",
        "cmdhead",
        "cmdtail",
        "echo",

        // c
        "list_element",
        "eval",
        "exec",
        "execute",

        // 10
        "exists",
        "fgets",
        "fprintf",
        "get_base",

        // 14
        "get_dext",
        "get_ext",
        "get_path",
        "getch",

        // 18
        "getenv",
        "getpid",
        "gets",
        "listlen",

        // 1c
        "makelist",
        "printf",
        "putenv",
        "stat",

        // 20
        "string_element",
        "strfind",
        "strformat",
        "strlen",

        // 24
        "strlwr",
        "resize",
        "strtok",
        "strupr",

        // 28
        "substr",
        "system",
        "trim",
        "trimleft",

        // 2c
        "trimright",
        "strchr",
        "listfind",
        "listunion",

        // 30
        "listConst",
};

size_t BuiltinFunctions::s_nFunctions = sizeof(s_name) / sizeof(char const *);
