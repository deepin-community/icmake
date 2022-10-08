//#define XERR
#include "scanner.ih"

void Scanner::setFiles()
{
    Arg const &arg = Arg::instance();

    if (arg.nArgs() == 0)               // no input file was specified
        return;

    filesystem::path inFile{ arg[0] };  // determine the input filename

    filesystem::path outFile;

    if (arg.nArgs() > 1)
        outFile =  arg[1];              // 2nd file was specified: use it
    else
    {
        outFile = inFile;                   // use inFile's base name,
        outFile.replace_extension(".pim");  // change its extension to .pim
    }

    if (inFile == outFile)
        throw Exception{} << "input/output filenames must differ";

    switchStreams(inFile.string(), outFile.string());
}
