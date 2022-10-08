//#define XERR
#include "generator.ih"

void Generator::setVersion()
{
    string version = VERSION;
    unsigned main = stoul(version);

    d_header.version[0] = main + (main >= 10 ? 'a' - 10 : '0');
    version.copy(d_header.version + 1, 3, version.find('.'));
}
