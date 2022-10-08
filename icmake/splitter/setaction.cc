#define XERR
#include "splitter.ih"

void Splitter::setAction()
{
    if (d_action == UNUSED)
    {
        d_action = static_cast<Action>(s_xlat.find(d_opt));

        d_actionIdx = d_optIdx;

        s_options[0] = { "define", required_argument, 0, 'd' };
        d_optstring += ':';
    }        
}
