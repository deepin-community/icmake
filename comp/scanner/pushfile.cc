//#define XERR
#include "scanner.ih"

void Scanner::pushFile()
{
    d_fileStack.top().second = lineNr();

    string name = matched().substr(2);              // the next filename

    setFilename(name);                              // update the scanner's
                                                    // current filename
    d_filenames += name + '\n';

    d_input->setLineNr(1);                          // and line nr

    d_fileStack.push( { filename(), 1 } );          // push the current 
                                                    // file name and line nr

xerr("stack[" << d_fileStack.size() << "]: " << filename() << ", " << lineNr());
}
