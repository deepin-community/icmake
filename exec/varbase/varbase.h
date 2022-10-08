#ifndef INCLUDED_VARBASE_
#define INCLUDED_VARBASE_

#include <iosfwd>
#include <vector>
#include <compare>
#include <string>

class VarBase
{
    friend bool operator==(VarBase const &lhs, VarBase const &rhs);
    friend std::strong_ordering operator<=>(VarBase const &lhs, 
                                            VarBase const &rhs);
    public:
        VarBase(VarBase const &other) = delete;

        virtual ~VarBase();

        VarBase *copy() const;

        bool isTrue() const;                            // Int, String, List
        bool isString() const;                          // Int, String, List
        int forcedInt() const;                          // Int, String, List

        int value() const;                              // Int
        int &valueRef();                                // Int

        std::vector<std::string> const &list() const;   // List
        std::string const &str() const;                 // String

        VarBase &operator+=(VarBase const &rhs);        // Int, String, List
        VarBase &operator-=(VarBase const &rhs);        // Int, List

        std::ostream &insertInto(std::ostream &out);    // Int, String, List

        std::string to_string() const;              // convert an argument to
                                                    // a string

    protected:
        VarBase() = default;

    private:  
                                        // shouldn't happen, but called when
                                        // derived classes didn't override a
                                        // virtual function
        [[noreturn]] void undefined() const;     

        // these members *may* be overridden:

        virtual std::vector<std::string> const &vList() const;
        virtual int  vValue() const;
        virtual int &vValueRef();
        virtual std::string const &vStr() const;
        virtual std::strong_ordering vOrder(VarBase const &rhs) const;
        virtual VarBase &vSubIs(VarBase const &rhs);
        virtual int vForcedInt() const;             // 0 for String and List

        // these members *must* be overridden:

        virtual bool vEqual(VarBase const &rhs) const = 0;
        virtual std::ostream &vInsertInto(std::ostream &out) const = 0;
        virtual bool vBool() const = 0;
        virtual VarBase &vAddIs(VarBase const &rhs) = 0;
        virtual std::string vto_string() const  = 0;
        virtual bool vIsString() const  = 0;
        virtual VarBase *vcopy() const  = 0;
};

#include "copy.f"
#include "forcedint.f"
#include "insertinto.f"
#include "isstring.f"        
#include "istrue.f"
#include "list.f"        
#include "str.f"
#include "tostring.f"
#include "value.f"
#include "valueref.f"

#include "opaddis.f"
#include "opequal.f"
#include "opspaceship.f"
#include "opsubis.f"

#endif
