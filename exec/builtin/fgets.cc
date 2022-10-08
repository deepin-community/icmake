#define XERR
#include "builtin.ih"

// The list has 4 values (output):
//      [0] - the read line
//      [1] - a '\n' if a newline was read
//      [2] - input: "OK": proceed;  output: "OK" or "FAIL"
//      [3] - input: starting offset, output: next offset
//
//  or empty: start reading from the file's beginning

void Builtin::fgets()
{
    enum
    {
        LINE,
        NL,
        OK,
        OFFSET
    };

    string const &fileName = d_stack[2].str();
    vector<string>list = d_stack[3].list();

    if (list.empty())
        list = { "", "\n", "OK", "0" };

    if (list[OK] == "OK")
    {
        ifstream in{ fileName };

        in.seekg(stoull(list[OFFSET]));     // go to the stream's offset

        if (not getline(in, list[LINE]))    // no more lines
            list.clear();
        else
        {
            list[OFFSET] = to_string(in.tellg());
            if (in.eof())
                list[OK] = "FAIL";
        }
    }

    d_reg = move(list);
}




