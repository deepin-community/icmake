//#define XERR
#include "handler.ih"

int Handler::preprocess()
{
    return direct(
            "icm-pp" + d_preOptions + ' ' + d_splitter.file1() + 
                                      ' ' + file2(".pim")
        );
}
