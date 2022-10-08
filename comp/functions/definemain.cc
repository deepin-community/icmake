#define XERR
#include "functions.ih"

void Functions::defineMain(ExprType type)
{
    d_info = &d_main;

    if (d_main.returnType != e_bool)
        Error::msg(Error::MAIN_NO_OVERLOADS);
    else if (type != e_void and type != e_int)
        Error::msg(Error::MAIN_RETURN_ERROR);
    else
    {
        d_main.returnType = type;
        d_main.offset = d_code.size() + sizeof(Header);
    }
}
