#define XERR
#include "handler.ih"

bool Handler::doCompile() const
{
    Stat outFile{ d_file2 };

    return 
        not outFile 
        or 
            Stat{ d_splitter.file1() }.statStruct().st_mtime 
            >=
            outFile.statStruct().st_mtime;
}
