//#define XERR
#include "bimheader.ih"

void BimHeader::seekg(int32_t step, ios::seekdir dir)
{
    d_in.seekg(step, dir);
    auto offset = d_in.tellg();
    if (not d_in or not (codeOffset() <= offset and offset < codeEndOffset()))
        throw Exception{} << "jmp leaves the code area";
}
