inline bool BimHeader::hasVariables() const
{
    return d_hdr.filenames > d_hdr.variables;
}
