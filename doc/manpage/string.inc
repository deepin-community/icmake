
bf(STRING FUNCTIONS:)

    itemization(
    itt(int ascii(string str))nl()
       returns the first character of tt(str) as an in: tt(ascii("A")) returns
        65;

    itt(string change_base(string file, string base))nl()
       returns tt(file) whose base name is changed into tt(base):
        tt(change_base("/path/demo.im", "out")) returns tt("/path/out.im");

    itt(string change_ext(string file, string ext))nl()
       returns tt(file) whose extension is changed into tt(ext):
        tt(change_ext("source.cc", "o")) returns tt("source.o"). The
        extension of the returned tt(string) is separated from the file's base
        name by a single dot (e.g., tt(change_ext("source.", ".cc"))
        returns tt("source.cc"));

    itt(string change_path(string file, string path))nl()
       return tt(file) whose path is changed into tt(path):
        tt(change_path("tmp/binary", "/usr/bin")) returns 
        tt("/usr/bin/binary"). To remove the path specify tt(path) as an empty
        string;

    itt(string element(int index, string var))nl()
       acts identically to the index operator: refer to the index (tt([]))
        operator in section bf(OPERATORS);

    itt(string get_base(string file))nl()
        returns the base name of tt(file). The base name is the file without
        its path prefix and without its extension. The extension is all
        information starting at the final dot in the filename. If no final dot
        is found, the file name is the base name. E.g., the base name of
        tt(a.b) equals tt(a), the base name of tt(a.b.c) equals tt(a.b), the
        base name of tt(a/b/c) equals tt(c);

    itt(string get_dext(string file))nl()
       returns the extension of tt(file), including the separating dot (hence
        the tt(d) in tt(dext)). The extension is all information starting at
        the filename's final dot. If tt(file) does not have a final dot then
        an empty string is returned;

    itt(string get_ext(string file))nl()
       returns the extension of tt(file), without the separating dot. The
        extension are all characters in tt(file) starting at tt(file's) final
        dot. If no final dot is found, an empty string is returned;

    itt(string get_path(string file))nl() 
       returns tt(file's) path-prefix. The path prefix is all information
        up to (and including) the final directory separator (which is,
        depending on the operating system, a forward slash or a backslash).
        If tt(file) does not contain a path-element, then an empty string is
        returned;

    itt(string resize(string str, int newlength)) 
       returns a copy of string tt(str), resized to tt(newlength) characters.
        If tt(newlength) is negative then an empty string is returned, if
        tt(newlength) exceeds tt(str's) length then the newly added characters
        are initialized to blank spaces;

    itt(int strchr(string str, string chars))nl()
       returns the first index in tt(str) where any of the characters in
        tt(chars) is found, or -1 if tt(str) does not contain any of the
        characters in tt(chars);

    itt(int strfind(string haystack, string needle))nl()
       returns index in tt(haystack) where tt(needle) is found, or -1 if
        tt(needle) is not found in tt(haystack);

    itt(string strformat(string format, argument(s)))nl()
       returns a string constructed from the tt(format) string containing
        placeholders %1 .. %2 to refer to arguments following the format
        string. The specification %1 refers to the first argument following
        the format string. If fewer arguments than tt(n) are provided then
        additional 0 arguments are provided by icm(). Example:nl() 
     verb(
    void main()
    {
        string s2 = = strformat("%1 %2 %1\n", 10, 20);
        printf("s2 = ", s2);        // shows: s2 = 10 20 10
    }
        )

    itt(int strlen(string str))nl()
       returns the number of characters in tt(str) (not counting the
        terminating NUL-character);

   itt(string strlwr(string str))nl()
       returns a lower-case duplicate of tt(str);

    itt(list strtok(string str, string separators))nl()
       returns a list containing all substrings of tt(str) separated by one
        or more (consecutive) characters in tt(separators):
        tt(strtok("hello icmake's+world", " +")) returns a list containing
        the three strings tt("hello"), tt("icmake's"), and tt("world");

    itt(string strupr(string str))nl()
       returns an upper-case duplicate of tt(str).

    itt(string substr(string text, int offset, int count))nl()
       returns a substring of tt(text), starting at tt(offset), consisting of
        tt(count) characters. If tt(offset) exceeds (or equals) the string's
        length or if tt(count <= 0), then an empty string is returned. If
        tt(offset) is less than 0 then tt(offset = 0) is used. If tt(offset +
        count) exceeds tt(text's) length then the available substring starting
        at tt(text[offset]) is returned (which may be empty);

    itt(string trim(string str))nl()
       returns a copy of tt(str) without leading and trailing white spaces;

    itt(string trimleft(string str))nl()
       returns a copy of tt(str) without leading white spaces;

    itt(string trimright(string str))nl()
        Returns a copy of tt(str) without trailing white spaces.
    )
