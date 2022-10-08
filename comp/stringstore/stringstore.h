#ifndef INCLUDED_STRINGSTORE_
#define INCLUDED_STRINGSTORE_

#include <string>
#include <vector>
#include <unordered_map>

    // Singleton

struct StringStore
{
    struct Info
    {
        unsigned    offset;
        std::string str;
    };

    private:
        std::vector<Info> d_string;         // the strings and their offsets in
                                            // the string area
    
        unsigned d_offset;                  // offset of the next string in the
                                            // string area
    
                        //  offset    index 
                        //          (in d_string)
        std::unordered_map<unsigned, unsigned>  d_indexOf;  // locate a string
                                                            // idx given its
                                                            // offset 
    
        static StringStore s_stringStore;       // defined in instance.cc

    public:
        StringStore(StringStore const &other) = delete;

        static StringStore &instance();

                                        // was: add(...)
        unsigned offset(std::string const &str);// returns offset of str
                                                // (adds it if a new str)

        std::string const &str(unsigned offset) const;  // returns str given 
                                                        // its offset

                                                // "123" -> 123
        int asInt(unsigned strOffset);          // returns 0 if no int-chars

        int constCompare(unsigned lhsOffset, unsigned rhsOffset) const;

        std::vector<Info> const &stringVect() const;    // the strings and  .f
                                                        // their offsets in
                                                        // the string area 

    private:
        StringStore();

};

#include "stringvect.f"

#endif
