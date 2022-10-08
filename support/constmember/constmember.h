#ifndef INCLUDED_CONSTMEMBER_
#define INCLUDED_CONSTMEMBER_

#include <utility>

template <typename Derived>
class ConstMember
{
    protected:
        template <void (Derived::*ptr)() const, typename ...Params>
        void nc(Params &&...params)
        {
            (static_cast<Derived *>(this)->*ptr)(
                                            std::forward<Params>(params)...
                                        ); 
        }
        // use: &Derived::nc<&Derived::func>
};
        
#endif
