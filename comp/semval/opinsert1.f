inline SemVal &operator<<(SemVal &semVal, uint8_t value)
{
    return semVal.insert1(value);
}
