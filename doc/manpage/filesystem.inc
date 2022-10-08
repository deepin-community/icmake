
bf(FILESYSTEM FUNCTIONS):

    itemization(
    itt(string chdir([int check,] string dir))nl()
       changes the script's working directory to tt(dir) (which may be
        specified as absolute or relative to the script's current working
        directory). The first argument is optional: if omitted and changing
        the working directory fails then the icm()-script ends with exit
        value 1; by specifying tt(P_NOCHECK) the function won't terminate the
        script but merely returns the script's current working directory. The
        script's working directory after completing the change-dir request is
        returned as an absolute path, ending in a `/' directory separator.

       Use tt(chdir(".")) to merely obtain the current working directory;
        use tt(chdir("")) to change-dir to the script's startup working
        directory; 

    itt(int exists(string file))nl()
       if tt(file) exists, 1 is returned, otherwise 0 is returned;

    itt(list fgets(string file, list offset))nl()
       the next line found at offset value tt(offset[3]) is read from
        tt(file). Pass an empty list to tt(fgets) to read tt(file) from its
        beginning.

       The returned list has four elements:
       quote(
       itemization(
        it() its first element ([0]) contains the read line (without the line's
            tt(\n) line terminator);

       it() its second element ([1]) contains the line's tt(\n) line
            terminator (or an empty string if the line was not terminated by a
            tt(\n));

       it() its third element ([2]) contains the string tt(OK) if the line was
            successfully read and tt(FAIL) if reading from file failed;

       it() its fourth element ([3]) contains the offset beyond the last read
            byte. 
        ))

       To read multiple lines, pass the returned list as argument to
        tt(fgets):
    verb(
    list ret;
    while (ret = fgets("filename", ret))
        process(ret);
    )
       Be careful not to define tt(list ret) in tt(while's) condition, as this
        will reset tt(ret) to an empty list at each iteration;

    itt(int fprintf(string filename, argument(s)))nl()
       appends all (comma or left-shift (insertion) operator separated)
        arguments to the file tt(filename). Returns the number of printed
        arguments.

       If the first argument (following tt(filename)) contains placeholders
        (tt(%1, %2, ... %n)) then that argument is considered a format string
        (see also the function tt(strformat) in the string functions section
        for additional information about format strings). Some examples:
  verb(
    fprintf("out", "hello", "world", '\n'); 
    fprintf << "out" << "hello" << "world" << '\n'; 

    fprintf("out", "%1 %2\n", "hello", "world");           // 1
    fprintf << "out" << "hello" << ' ' << "world" << '\n'; // 2
    fprintf << "out" << "%1 %2\n" << "hello" << "world";   // 3
  )
    When writing statement 1 using insertion operators (cf. the expression
        statement description in section tt(FLOW CONTROL))  statement 2 would
        normally be encountered, although statement 3, using the format
        string, would still be accepted;

    itt(string getch())nl()
       returns the next pressed key as a string (pressing the `Enter'-key is
        not required). The pressed key is not echoed. If the key should be
        echoed use, e.g., tt(printf(getch()));


    itt(string gets())nl()
       returns the next line read from the keyboard as a tt(string). The line
        contains all entered characters until the `Enter'-key was pressed. The
        `Enter'-key's value itself is not stored in the returned string;

    itt(list makelist([int type = O_FILE], string mask))nl() 
       the argument tt(type) is optional, in which case tt(O_FILE) is used.
        tt(Makelist) returns a list of all tt(type) file-system entries
        matching tt(mask). E.g., tt(makelist("*.c")) returns a list containing
        all files ending in tt(.c). For tt(type) one of the following set of
        values can be used to obtain a more specific selection of directory
        entries:
    table()(ll)(
        rowline()
        row(cell(symbol)cell(meaning))
        rowline()
        row(cell(O_ALL)cell(obtain all directory entries))
        row(cell(O_DIR)cell(obtain all directories, including . and ..))
        row(cell(O_FILE)cell(obtain a list of regular files))
        row(cell(O_SUBDIR)cell(obtain all directories except for . and ..))
        rowline()
    )
       In Unix-type operating systems the pattern tt(*) does not match
        entries starting with a dot (hidden entries). To obtain a list of such
        entries use the pattern tt(.*);

    itt(list makelist([int type = O_FILE,] string mask, {newer,older,younger},
        string comparefile))nl()
       the (optional) parameter tt(type) may be specified as in the previous
        variant of tt(makelist). The third parameter must be either tt(newer)
        (or tt(younger)) or tt(older). A list of all file-system entries
        matching mask which are, resp., newer or older than a provided
        tt(comparefile) is returned. Note that tt(newer) and tt(younger) are
        operators, not strings;

    itt(int printf(argument(s)))nl()
       the function's (comma or left-shift (insertion) operator separated)
        arguments are written to the standard output file (cf.  the expression
        statement description in section tt(FLOW CONTROL) and this section's
        description of the tt(fprintf) function). If the first
        argument contains tt(%1, %2, ... %n) specifications then it's
        considered a format string (see also the function tt(strformat) in the
        tt(STRING FUNCTIONS) section for additional information about format
        strings). Like tt(fprintf printf) returns the number of printed
        arguments;

    itt(list stat([int check,] string entry))nl()
       Returns bf(stat)(2) information of directory entry tt(entry) as a
        list. The first argument is optional: if omitted and calling the
        system tt(stat) function fails then the icm()-script ends with exit
        value 1; by specifying tt(P_NOCHECK) the function won't terminate the
        script but returns the return value (-1) of the system tt(stat)
        function. 

       The returned list has two elements:

       its first element ([0]) holds the entry's attributes.  Attributes are
        returned as the file type and mode of the specified file
        (cf. bf(stat)(2) and bf(inode)(7)). E.g.,
      verb(
    S_IRUSR  - owner has read permission
    S_IWUSR  - owner has write permission
    S_IXUSR  - owner has execute permission

    S_IFSOCK - socket
    S_IFLNK  - symbolic link
    S_IFREG  - regular file
    S_IFBLK  - block device
    S_IFDIR  - directory
    S_IFCHR  - character device
    S_IFIFO  - FIFO
    )
       its second element ([1]) contains the entry's size in bytes. If
        tt(P_NOCHECK) was specified and 'entry' doesn't exists then a list
        having one element is returned containing -1.
    )
