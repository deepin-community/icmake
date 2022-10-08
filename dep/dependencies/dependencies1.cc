//#define XERR
#include "dependencies.ih"

Dependencies::Dependencies(Options const &options)
:
    d_options(options),
    d_useAll(options.useAll()),
    d_directory{ "." },         // see also 'readClasses'
    d_dirWidth(size("class:"))  // see showDependencies
{
    addDirectory(options.parser());
    addDirectory(options.scanner());

    d_size = readClasses();

    setClassIdx();
    d_classCount.resize(d_size);

    d_dependency = identityMatrix(d_size);

    d_localHeader.resize(d_size);   // stores locally included header files
}
