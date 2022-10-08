
bf(LIST FUNCTIONS:)

    itemization(
    itt(string element(int index, list var))nl()
       acts identically to the index operator: refer to the index (tt([]))
        operator in section bf(OPERATORS);

    itt(int listfind(list lst, string str))nl()
       returns the smallest index in tt(lst) where the string
        tt(str) is found, or -1 if tt(lst) does not contain tt(str);

    itt(int listlen(list l))nl()
        returns the number of elements in tt(list);

    itt(list listunion(list lhs, list rhs))nl()
       returns a list containing the union of the elements in tt(lhs) and the
        elements of tt(rhs). The original order of the elements in tt(lhs) is
        kept. Subsequent elements in tt(rhs) that are not available in tt(lhs)
        are added to the end of tt(lhs);

    itt(list listunion(list lst, string str))nl()
       returns a list containing the union of the elements in tt(lst) and
        tt(str). The original order of the elements in tt(lhs) is kept. If
        tt(rhs) is not available in tt(lhs) then it is added to the end of
        tt(lhs).
    )

