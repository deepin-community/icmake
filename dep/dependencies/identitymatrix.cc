//#define XERR
#include "dependencies.ih"

// static
BoolMatrix Dependencies::identityMatrix(size_t dimension)
{
    BoolMatrix ret(dimension);
    
    size_t diag = 0;
    for (auto &vect: ret)
    {
        vect.resize(dimension);
        vect[diag] = true;
        ++diag;
    }
    
    return ret;                     // return a bool identity matrix of 
}                                   // dimension x dimension elements
