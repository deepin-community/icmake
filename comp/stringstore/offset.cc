#define XERR
#include "stringstore.ih"

unsigned StringStore::offset(string const &str)
{
    if (
        auto iter = find_if(d_string.begin(), d_string.end(),
            [&](Info const &info)
            {
                return info.str == str;     // find str in existing strings
            }
        );
        iter != d_string.end()
    )
        return iter->offset;                // return offset of existing str.

    d_indexOf.insert({ d_offset, d_string.size() });    // index given offset
    d_string.push_back({ d_offset, str });              // string info itself

    unsigned ret = d_offset;

    d_offset += str.size() + 1;             // add 1 for \0

    return ret;
}
