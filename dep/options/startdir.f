inline void Options::startDir() const
{
    std::filesystem::current_path(d_cwd);
}
