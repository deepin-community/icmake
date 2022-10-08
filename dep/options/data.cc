//#define XERR
#include "options.ih"

Pattern Options::s_icmconf
{
    "^[ \t]*#define[ \t]*"
        "([^ \t]+)"     //      [1]: key 
        "[ \t]*\""
        "([^\"]+)?"     //      [2]: value (opt)
        "\""        
};

unordered_map<std::string, void (Options::*)()> Options::s_icmconfEntry = 
{
    { "PRECOMP",     &Options::precomp    },
    { "IH",          &Options::ih         },
    { "USE_ALL",     &Options::setUseAll  },
    { "PARSER_DIR",  &Options::parserDir  },
    { "SCANNER_DIR", &Options::scannerDir },
};

