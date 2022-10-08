//#define XERR
#include "symtab.ih"

    // find 'name' in VarVect vect: vect is the vector at an externally
    // determined level 
    //
int Symtab::find(VarVect const &vect, string const &name) const
{
    auto iter = find_if(vect.begin(), vect.end(), 
                    [&](auto const &element)
                    {                           // true: already defined
                        return element.name == name;    
                    }
                );

    return iter == vect.end() ? -1 : iter - vect.begin();    
}
