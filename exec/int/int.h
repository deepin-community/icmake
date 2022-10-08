#ifndef INCLUDED_INT_
#define INCLUDED_INT_

#include "../varbase/varbase.h"

class Int: public VarBase
{
    int d_value = 0;

    public:
        Int(int value = 0);                                             // 1.f
        
        ~Int() override;

    private:
        // these members *may* be overridden:

        int  vValue() const override;
        int &vValueRef() override;
        std::strong_ordering vOrder(VarBase const &rhs) const override;
        VarBase &vSubIs(VarBase const &rhs) override;

        // these members *must* be overridden:

        bool vEqual(VarBase const &rhs) const override;
        std::ostream &vInsertInto(std::ostream &out) const override;
        bool vBool() const override;
        VarBase &vAddIs(VarBase const &rhs) override;
        int vForcedInt() const override;
        std::string vto_string() const override;
        bool vIsString() const  override;
        VarBase *vcopy() const override;
};

#include "int1.f"
        
#endif
