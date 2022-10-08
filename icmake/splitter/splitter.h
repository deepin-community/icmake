#ifndef INCLUDED_SPLITTER_
#define INCLUDED_SPLITTER_

#include <string>
#include <vector>

struct option;

struct Splitter
{
    enum Action
    {
        COMPILE,   
        DEP,       
        EXEC,      
        FORCED,    
        PREPROCESS,
        SOURCE,    
        SCRIPT,    
        UNASSEMBLE,
        
        ABOUT,
        HELP,
        VERS,

        UNUSED,
    };

    std::vector<char *> d_ptrs;             // ptrs to the argv-like args

    unsigned d_argc;
    char **d_argv;

    bool d_process = true;
    bool d_verbose = false;
    bool d_pimFile = false;                 // by default -c/-f assume their
                                            // input files are scripts, With
                                            // -P they assume input files are
                                            // .pim files

    std::string d_versionCheck;
    std::string d_optstring;
    std::string d_tmpDir;
    std::string d_scriptBim;
    std::string d_pidName;

    std::string d_file1;
    std::string d_file2;
    unsigned d_nFiles = 0;

    int d_opt = 0;

    Action d_action = UNUSED;

    unsigned d_optIdx = 0;
    unsigned d_actionIdx = 0;
    unsigned d_execute = 0;
    unsigned d_preProcess = 0;

    static std::string s_xlat;
    static option s_options[];
    static char s_empty[];

    public:
        Splitter(unsigned argc, char **argv);

        unsigned argc() const;
        char const *const *argv() const;
        char const *argv(unsigned idx) const;
        void setArgv(unsigned idx, char *ptr);

        void show() const;

        std::string const &versionCheck() const;  // empty or starts with ' '
        bool process() const;
        bool verbose() const;
        bool pimFile() const;

        std::string const &tmpDir() const;
        std::string const &scriptBim() const;
        std::string const &pidName() const;

        Action actionOpt() const;           // requested action (like -c)
        unsigned actionIdx() const;         // idx of the action option

        unsigned endOpts() const;           // 1st non-option (file or
                                            // undefined option)

        std::string const &file1() const;   // empty string or ' '+name at 
                                            // endOpts
        std::string const &file2() const;   // empty string or ' '+name
                                            // following file1

        unsigned nFiles() const;            // #files at endOpts()

        unsigned actionArgsIdx() const;     // idx following the action option

        unsigned execute() const;           // idx of -e option (-s, -t)
        unsigned preProcess() const;        // idx of -p option (-s, -t)


    private:
        void getOpts();
        void endAction();
        void setAction();
        void action(unsigned *index);
        void depOrDef();

        void setFiles();                    // assign d_file[12] / d_nFiles
        std::string setFile(unsigned idx);  // "" or " filename"

        void setTmpDir();
        void setScriptBim();

        void scriptOption();
        void inspect(char *tArguments);

        void sourceOption();

        bool writable(std::string &dirName);
        static char const *getHome();
};

inline std::string const &Splitter::versionCheck() const
{
    return d_versionCheck;
}

inline bool Splitter::process() const
{
    return d_process;
}

inline bool Splitter::pimFile() const
{
    return d_pimFile;
}

inline bool Splitter::verbose() const
{
    return d_verbose;
}

inline std::string const &Splitter::tmpDir() const
{
    return d_tmpDir;
}

inline std::string const &Splitter::scriptBim() const
{
    return d_scriptBim;
}

inline unsigned Splitter::endOpts() const
{
    return d_optIdx;
}

inline unsigned Splitter::actionArgsIdx() const
{
    return d_actionIdx + 1;
}

inline Splitter::Action Splitter::actionOpt() const
{
    return d_action;
}

inline unsigned Splitter::actionIdx() const
{
    return d_actionIdx;
}

inline unsigned Splitter::execute() const
{
    return d_execute;
}

inline unsigned Splitter::preProcess() const
{
    return d_preProcess;
}

inline unsigned Splitter::argc() const
{
    return d_argc;
}

inline char const *const *Splitter::argv() const
{
    return d_argv;
}

inline char const *Splitter::argv(unsigned idx) const
{
    return d_argv[idx];
}

inline void Splitter::setArgv(unsigned idx, char *ptr)
{
    d_argv[idx] = ptr;
}

inline std::string const &Splitter::file1() const
{
    return d_file1;
}

inline std::string const &Splitter::file2() const
{
    return d_file2;
}
        
inline unsigned Splitter::nFiles() const
{
    return d_nFiles;
}

inline std::string const &Splitter::pidName() const
{
    return d_pidName;
}

#endif
