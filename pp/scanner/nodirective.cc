#include "scanner.ih"

void Scanner::noDirective()
{
    if (d_active)
    {
        s_matchDirective << matched();  // obtain the identifier beyond '#'
        fatal() << "directive `" << s_matchDirective[0] << 
                                                        "' not supported\n";
    }

    while (true)                        // skip all chars to \n or EOF
    {
        switch (lex())
        {
            case 0:
            return;

            case '\n':
                redo(1);
            return;

            default:
            break;
        }
    }
}
