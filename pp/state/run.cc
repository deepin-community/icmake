//#define XERR
#include "state.ih"

int State::run()
{
    int token;

    d_scanner.writeFilename();
    
    while (true)
    {
        token = d_scanner.lex();

        xerr("token = " << d_scanner.tokenName(token) << \
             ", state = " << s_stateName[d_state]);
            

        if (token == Scanner::ALL_DONE)
            return d_scanner.nErrors();

        (this->*s_state[token][d_state])(); // see data.cc, d_state may be 
                                            // altered by the member functions
    }
}
