// static
inline unsigned Tools::versionNr(char const *version)
{
    return std::stoul(version, 0, *version <= '9' ? 10 : 36);
                            // *version > '9' -> letter ->
                            // 26 letters + 10 digits -> base = 36
}
