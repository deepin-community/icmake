//#define XERR
#include "stringstore.ih"

int StringStore::asInt(unsigned strOffset)
{
    auto iter = d_indexOf.find(strOffset);  // iter->second is the index in
                                            // d_string

    if (iter == d_indexOf.end())
        fmsg << "internal error: no string at offset " << strOffset << noid;

    try
    {
        return stoi(d_string[iter->second].str);    // convert to int
    }
    catch (...)
    {
        return 0;                                   // or return 0
    }
}
