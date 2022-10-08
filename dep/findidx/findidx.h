#ifndef INCLUDED_FINDIDX_
#define INCLUDED_FINDIDX_

#include <algorithm>

//Predicate must accept a *RAiter argument and must return a bool
//
//
//RAiter and Type must be comparable:
//    *RAiter -> Type2
//    Type2 == Type
//    Type2 != Type
//    
//RAiter must have:
//    RAiter + size_t -> RAiter
//    RAiter - RAiter -> size_t
//    
//Containers must have:
//    begin() -> RAiterator
//    end()   -> RAiterator



    // subrange indices: find a value
    //
template <typename Container, typename Type>
size_t findIdx(Container const &container, size_t begin, size_t end, 
               Type const &value)
{
    auto ret = std::find(container.begin() + begin, 
                         container.begin() + end, value);

    return ret == container.end() ? end : ret - container.begin();
}     

    // indices start at 'begin' to the container's end: find a value
    //
template <typename Container, typename Type>
inline size_t findIdx(Container const &container, size_t begin, 
                      Type const &value)
{
    return findIdx(container, begin, container.size(), value);
}     

//     // inspect all the container's elements: find a value
//     //
// template <typename Container, typename Type>
// inline size_t findIdx(Container const &container, Type const &value)
// {
//     return findIdx(container, 0, container.size(), value);
// }     

//     // subrange indices: use a predicate
//     //
// template <typename Container, typename Predicate>
// inline size_t findIdx_if(Container const &container, size_t begin, size_t end,
//                          Predicate &&pred)
// {
//     auto ret = std::find_if(container.begin() + begin, container.begin() + end, 
//                             std::forward<Predicate>(pred));
//     return ret == container.end() ? end : ret - container.begin();
// }
// 
//     // indices start at 'begin' to the container's end: use a predicate
//     //
// template <typename Container, typename Predicate>
// inline void findIdx_if(Container const &container, size_t begin, 
//                        Predicate &&pred)
// {
//     findIdx_if(container, begin, container.size(), 
//                std::forward<Predicate>(pred));
// }
// 
//     // inspect all the container's elements: use a predicate
//     //
// template <typename Container, typename Predicate>
// inline void findIdx_if(Container const &container, Predicate &&pred)
// {
//     findIdx_if(container, 0, container.size(), 
//                std::forward<Predicate>(pred));
// }

#endif

