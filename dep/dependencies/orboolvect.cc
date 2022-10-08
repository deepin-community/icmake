//#define XERR
#include "dependencies.ih"

    // check all elements in rsh and set all 'false' elements in lhs that
    //  correspond to 'true' elements in rhs to 'true'
    // return 'true' if at least one element in lhs was modified.

// static
bool Dependencies::orBoolVect(BoolVect &lhs, BoolVect const &rhs)
{
    bool changed = false;

    auto lhsBegin = lhs.begin();

    auto rhsEnd = rhs.end();                        // visit all rhs elements
    auto rhsIter = rhs.begin();
    auto rhsBegin = rhsIter;

    while (true)
    {
        rhsIter = std::find(rhsIter, rhsEnd, true); // find 'true' elements

        if (rhsIter == rhsEnd)                      // reached the end -> 
            return changed;                         // return 'changed'

                                                // the matching lhs element
        auto lhsIter = lhsBegin + (rhsIter - rhsBegin);

        if (not *lhsIter)                       // update it when needed
        {
            changed = true;
            *lhsIter = true;
        }

        ++rhsIter;
    }
}
