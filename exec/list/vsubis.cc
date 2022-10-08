//#define XERR
#include "list.ih"

VarBase &List::vSubIs(VarBase const &rhs)
{
    auto rhsList = rhs.list();              // vector of strings in rhs List

    auto iter = remove_if(d_list.begin(), d_list.end(), 
        [&](string const &element)
        {
                                // returns true is element is in rhs
            return find(rhsList.begin(), rhsList.end(), element) 
                    != rhsList.end();
        }
    );

    d_list.resize(iter - d_list.begin());

    return *this;
}

