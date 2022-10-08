//#define XERR
#include "dependencies.ih"

Pattern Dependencies::s_include
{
        R"_(^[ \t]*#include[ \t]*)_"            // #include "

        "\"("
    //     1

        R"_(([^"/]+))_"                         // #=3, (hdr) @2
    //      2                                      #include "hdr"

        "|"

        R"_(\.\./([^"/]+))_"                    // #=4, ../(hdr) @3
    //           3                                 #include "../hdr"

        "|"

        R"_(([^"/]+)/([^"/]+))_"                // #=6 (sub)/(hdr), 
    //      4        5                                 @4    @5
    //                                              #include "dir/hdr"

        "|"

        R"_(\.\./([^"/]+)/([^"/]+))_"           // #=8, ../(sub)/(hdr)
    //           6        7                                @6    @7
    //                                              #include "../sub/hdr"
 
        ")\"",
};
