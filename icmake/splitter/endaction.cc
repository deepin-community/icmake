#define XERR
#include "splitter.ih"

void Splitter::endAction()
{
    d_action = static_cast<Action>(s_xlat.find(d_opt));
    d_actionIdx = d_optIdx;
}
