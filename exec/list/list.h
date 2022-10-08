#ifndef INCLUDED_LIST_
#define INCLUDED_LIST_

#include <vector>
#include <string>

#include "../varbase/varbase.h"

class List: public VarBase
{
    std::vector<std::string> d_list;

    public:
        List() = default;
        List(std::vector<std::string> &&tmp);                       // 1.cc

        ~List() override;

        std::string const &operator[](size_t idx) const;

    private:
        std::vector<std::string> const &vList() const override;
        VarBase &vSubIs(VarBase const &rhs) override;

        // these members *must* be overridden:

        bool vEqual(VarBase const &rhs) const override;
        std::ostream &vInsertInto(std::ostream &out) const override;
        bool vBool() const override;
        VarBase &vAddIs(VarBase const &rhs) override;
        std::string vto_string() const override;
        bool vIsString() const override;
        VarBase *vcopy() const override;
};
        
#endif


