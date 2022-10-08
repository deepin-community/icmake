inline void BimHeader::start()
{
    return readFrom(d_hdr.firstOpcode);
}
