#ifndef INCLUDED_VARIABLE_
#define INCLUDED_VARIABLE_

#include <ostream>
#include <memory>
#include <compare>

#include "../varbase/varbase.h"

class Variable: private std::unique_ptr<VarBase> 
{
    friend std::ostream &operator<<(std::ostream &out, Variable const &var);
    friend bool operator==(Variable const &lhs, Variable const &rhs);
    friend std::strong_ordering operator<=>(Variable const &lhs, 
                                            Variable const &rhs);

    public:
        Variable(VarBase *ptr = 0); 
        Variable(Variable const &other);
        Variable(Variable &&tmp);

        Variable &operator=(Variable const &other);
        Variable &operator=(Variable &&tmp) = default;

        Variable &operator=(int value);                             // 1.cc
        Variable &operator=(std::string const &str);                // 2.cc
        Variable &operator=(std::string &&tmp);                     // 3.cc
        Variable &operator=(std::vector<std::string> &&tmp);        // 4.cc

        bool isTrue() const;                    // Int, String, List
        bool isString() const;                  // Int, String, List

        int value() const;
        int &valueRef();
                                            // force the interpretation as int  
        int forcedInt() const;              // (used by d_reg when run() ends

        std::string const &str() const;
        std::vector<std::string> const &list() const;

        Variable &operator+=(Variable const &rhs);  // Int, String, List
        Variable &operator-=(Variable const &rhs);  // Int, List

        std::string to_string() const;              // convert an argument to
                                                    // a string

        void swap(Variable &other);
};

#include "forcedint.f"
#include "isstring.f"        
#include "istrue.f"
#include "list.f"        
#include "str.f"
#include "tostring.f"
#include "value.f"
#include "valueref.f"

#include "opaddis.f"
#include "opequal.f"
#include "opinsert.f"
#include "opspaceship.f"
#include "opsubis.f"

#endif
