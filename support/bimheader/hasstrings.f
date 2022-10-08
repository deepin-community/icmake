inline bool BimHeader::hasStrings() const
{
    return d_hdr.variables > d_hdr.strings;
}
