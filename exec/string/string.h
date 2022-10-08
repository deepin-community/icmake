#ifndef INCLUDED_STRING_
#define INCLUDED_STRING_

#include <string>

#include "../varbase/varbase.h"

class String: public VarBase
{
    std::string d_str;

    public:
        String(std::string const &str = "");                            // 1.f

        ~String() override;

    private:
        // these members *may* be overridden:

        std::string const &vStr() const override;
        std::strong_ordering vOrder(VarBase const &rhs) const override;

        // these members *must* be overridden:

        bool vEqual(VarBase const &rhs) const override;
        std::ostream &vInsertInto(std::ostream &out) const override;
        bool vBool() const override;
        VarBase &vAddIs(VarBase const &rhs) override;
        std::string vto_string() const override;
        bool vIsString() const override;
        VarBase *vcopy() const override;
};

#include "string1.f"

#endif
