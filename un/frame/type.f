inline uint8_t Frame::type(int16_t idx) const
{
    return (*this)[-idx - 1];
}
