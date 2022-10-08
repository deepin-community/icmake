//#define XERR
#include "builtin.ih"

char const Builtin::s_space[] = " \t\f\n\r\v";

//                              1
Pattern Builtin::s_percent{ R"(%(\d+))" };

std::unordered_map<int, Builtin::GlobSpecs> const Builtin::s_globSpecs =
{
                //  type                  flags
    { O_ALL,    { Glob::ANY,            Glob::PERIOD | Glob::NOMATCH } },
    { O_DIR,    { Glob::DIRECTORY,      Glob::PERIOD | Glob::NOMATCH } },
    { O_FILE,   { Glob::REGULAR_FILE,   Glob::PERIOD | Glob::NOMATCH } },
    { O_SUBDIR, { Glob::DIRECTORY,      Glob::NOMATCH } },
};

// See ../../support/builtinfunctions/builtinfunctions.h
void(Builtin::*Builtin::s_function[])() =
{
    // 0
    &Builtin::argHead,
    &Builtin::argTail,
    &Builtin::asciiStr2int,
    &Builtin::asciiInt2str,

    // 4
    &Builtin::backtick,
    &Builtin::changeBase,
    &Builtin::changeExtension,
    &Builtin::changePath,

    // 8
    &Builtin::chdir,
    &Builtin::cmdHead,
    &Builtin::cmdTail,
    &Builtin::echo,

    // c
    &Builtin::listElement,
    &Builtin::backtick,             // the eval() call is handled by backtick
    &Builtin::exec,
    &Builtin::exec,                 // execute is only used by the compiler,
                                    // there's no need for a separate function
    // 10
    &Builtin::exists,
    &Builtin::fgets,
    &Builtin::fprintf,
    &Builtin::getBase,

    // 14
    &Builtin::getDotExtension,
    &Builtin::getExtension,
    &Builtin::getPath,
    &Builtin::getCh,

    // 18
    &Builtin::getEnvironVar,
    &Builtin::getPid,
    &Builtin::gets,
    &Builtin::listLen,

    // 1c
    &Builtin::makeList,
    &Builtin::printf,
    &Builtin::putEnvironment,
    &Builtin::stat,

    // 20
    &Builtin::strElement,
    &Builtin::strFind,
    &Builtin::strFormat,
    &Builtin::strLength,

    // 24
    &Builtin::strLowercase,
    &Builtin::resize,
    &Builtin::strTok,
    &Builtin::strUppercase,

    // 28
    &Builtin::substring,
    &Builtin::system,
    &Builtin::trim,
    &Builtin::trimLeft,

    // 2c
    &Builtin::trimRight,
    &Builtin::strChr,
    &Builtin::listFind,
    &Builtin::listUnion,

    // 30
    &Builtin::listConstruct,
};
