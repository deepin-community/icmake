#ifndef INCLUDED_TOOLS_
#define INCLUDED_TOOLS_

#include <time.h>

#include <iosfwd>
#include <string>
#include <utility>
//#include <system_error>
#include <filesystem>

namespace FBB
{
    class Stat;
}

class Tools
{
    using Path = std::filesystem::path;

    static std::error_code s_ec;

    public:
        static std::string absolute(std::string const &dir);
        static Path currentPath();                              // 1.cc
        static void currentPath(Path const &next);              // 2.cc
        static bool createDirectories(Path const &dir);

        static bool exists(std::string const &path);        // these use
        static bool remove(std::string const &path);        // 'filesystem'
        static bool changeDir(std::string const &path);     // 
        static void mustChangeDir(std::string const &path); // throws an
                                                            // exception on
                                                            // failure

        static bool younger(std::string const &entry, FBB::Stat const &rhs);
        static bool older(std::string const &entry, FBB::Stat const &rhs);

                                                // convert main version number
                                                // to unsigned (>a -> >10)
        static unsigned versionNr(char const *version);  

                                                // append Type's bytes to dest
        template <typename Type>                                        // 1.f
        static void append(std::string &dest, Type value);

        template <typename UseType, typename Type>                      // 2.f
        static void append(std::string &dest, Type value);

        static std::ostream &usageTop(std::string const &progname, 
                                      bool showUsage = true);

        static std::string compilerSpec(char const *arg1, 
                                        std::string const &stdCmd);

        static std::string command(std::string const &moldCmd, 
                    std::string const &dollar1, std::string const &dollar2);
                                                    
        static bool createSymlink(std::string const &dest, 
                                   std::string const &link);

    private:
        static std::string &setPath(std::string &cmd);

                                        // determine last modification seconds
                                        // of 'entry' and an existing Stat
        static std::pair<time_t, time_t> times(std::string const &entry, 
                                               FBB::Stat const &rhs);
};

#include "append1.f"
#include "append2.f"
#include "versionnr.f"

#endif
