// Generated by Flexc++ V2.07.07 on Thu, 05 Mar 2020 17:53:53 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

#include <string>
#include <stack>

// $insert baseclass_h
#include "scannerbase.h"

// $insert classHead
class Scanner: public ScannerBase
{
    size_t d_expr;             // operator exprs or numeric exprs made
                                // available by token()
                                // (see also ../operators/operators.h)

    std::stack< std::pair<std::string, size_t> > d_fileStack;
    std::string d_filenames;    // all filenames, including terminating '\n'

    public:
        Scanner(std::string const &infile, std::string const &outfile);
        
        // $insert lexFunctionDecl
        int lex();

        int expr() const;
        std::string const &filenames() const;                       // .f

    private:
        void setWhere() const;  // filename linenr info: modifies g_where
        int token(int token, size_t expr);

        int cleanString();      // remove surrounding quotes and unescape
                                // matched(), then return Tokens::STRING

        void setLineNr();       // update Input's lineNr at ^#<nr> lines
        void pushFile();        // update the current file at ^#\> lines
        void popFile();         // restore the previous filename/line nr

        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.

};

#include "lex.f"
#include "print.f"
#include "precode.f"
#include "postcode.f"
#include "expr.f"
#include "filenames.f"

#endif // Scanner_H_INCLUDED_

