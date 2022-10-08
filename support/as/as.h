#ifndef INCLUDED_AS_
#define INCLUDED_AS_

template <typename Out, typename In>
inline constexpr Out as(In &&in)
{
    return static_cast<Out>(in);
}

#endif
