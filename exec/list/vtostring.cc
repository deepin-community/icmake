//#define XERR
#include "list.ih"

string List::vto_string() const
{
    ostringstream os;

    vInsertInto(os);

    return os.str();
}
