//#define XERR
#include "scanner.ih"

Scanner::Scanner(std::string const &infile, std::string const &outfile)
:
    ScannerBase(infile, outfile)
{
    d_fileStack.push( { infile, lineNr() } );       // push the current 
                                                    // file name and line nr
    d_filenames = infile + '\n';

    setWhere();

xerr("stack[" << d_fileStack.size() << "]: " << infile << ", " << lineNr());
}
