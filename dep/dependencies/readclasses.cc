//#define XERR
#include "dependencies.ih"

size_t Dependencies::readClasses()
{
    ifstream in{ d_options.classes() };     // this may fail: a CLASSES
                                            // file may not exist

    string line;
    while (getline(in, line))
    {
        istringstream ins{ line };
        if (
            not (ins >> line)                   // no first word
            or
            "#/"s.find(line[0]) != string::npos // or 1st char is # or /
        )
            continue;                           // then ignore this line

        addDirectory(line);                     // add the dir-name
    }

    return d_directory.size();
}


