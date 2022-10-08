#define XERR
#include "functions.ih"

namespace
{
    initializer_list<ExprType> mainParams{ e_int, e_list, e_list };
}

void Functions::checkMainParams() const
try
{
    if (d_info->params.size() > 3)
        throw 1;

    auto beginReq = mainParams.begin();
    for (auto const &param: d_info->params)
    {
        if (*beginReq++ != (param & e_mask))
            throw 1;
    }
}
catch (...)
{
    Error::msg(Error::MAIN_PARAMS_ERROR);
}

