//#define XERR
#include "scanner.ih"

void Scanner::popFile()
{
    if (d_fileStack.size() == 1)
        wmsg << filename() << " line " << 
                                d_input->trueLineNr() << 
                                ": `#>...'/`#' lines mismatch" << endl;
    else
    {
        d_fileStack.pop();
        setFilename(d_fileStack.top().first);
        d_input->setLineNr(d_fileStack.top().second);
        setWhere();
    }

xerr("stack[" << d_fileStack.size() << "]: " << \
filename() << ", " << lineNr());
}
