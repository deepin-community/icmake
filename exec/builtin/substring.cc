//#define XERR
#include "builtin.ih"

void Builtin::substring()
{
    string const &str = d_stack[2].str();
    uint16_t idx = d_stack[3].value();

    d_reg =  idx >= str.length() ? 
                string{} 
            : 
                str.substr(idx, as<uint16_t>(d_stack[4].value()));
}
