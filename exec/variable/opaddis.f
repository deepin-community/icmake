inline Variable &Variable::operator+=(Variable const &rhs)
{
    *get() += *rhs.get();
    return *this;
}
