#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <unordered_map>
#include <filesystem>

#include <bobcat/arg>

#include "../action/action.h"

namespace FBB
{
    class Pattern;
    class Arg;
}

class Options
{
    FBB::Arg const &d_arg;

    std::string d_cwd;
    std::string d_classes{ "CLASSES" };
    std::string d_icmconf{ "icmconf" };
    std::string d_mainIH { "main.ih" };
    std::string d_useAll { "\0"      }; // by default use the icmconf spec
                                        // changed to the name of the USE_ALL
                                        // file or empty
    std::string d_ih     { ".ih" };
    std::string d_parser;
    std::string d_scanner;

    Action d_gch = UNSPECIFIED;
    Action d_go = DRY;

    static FBB::Pattern s_icmconf;
    static std::unordered_map<std::string, void (Options::*)()> 
                                                            s_icmconfEntry;
    public:
        Options();

        Action go() const;
        Action gch() const;

        void startDir() const;
        std::string const &classes() const;
        std::string const &scanner() const;
        std::string const &parser() const;
        std::string const &useAll() const;
        std::string const &mainIH() const;
        std::string const &dotIH() const;

        size_t verbosity() const;

    private:
        void setVerbosity() const;

        void scanIcmconf();

        void precomp();
        void ih();
        void setUseAll();
        void parserDir();
        void scannerDir();
};

#include "go.f"
#include "gch.f"
#include "startdir.f"
#include "classes.f"
#include "scanner.f"
#include "parser.f"
#include "mainih.f"
#include "dotih.f"
#include "verbosity.f"
#include "useall.f"
        
#endif
