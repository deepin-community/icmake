//#define XERR
#include "error.ih"

// static
void Error::msg()
{
    if (display())
        cout << g_where << s_static[s_error] << '\n';
}
