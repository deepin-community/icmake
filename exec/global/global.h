#ifndef INCLUDED_GLOBAL_
#define INCLUDED_GLOBAL_

#include <vector>

#include "../variable/variable.h"

class BimHeader;

class Global: private std::vector<Variable>
{
    public:
        Global(BimHeader &hdr);

        using std::vector<Variable>::operator[];

    private:
};
        
#endif
