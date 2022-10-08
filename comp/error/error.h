#ifndef INCLUDED_ERROR_
#define INCLUDED_ERROR_

#include <ostream>

class Error
{
    static char const *s_static[];
    static char const *s_semantic[];

    static size_t s_nErrors;
    static size_t s_error;
    static size_t s_lastLine;
    static size_t s_displayCount;

    enum 
    {
        MAX_PER_LINE = 2
    };

    public:
        enum Static
        {
            OFF,                    
            CLOSEPAREN,             
            COMMA_OR_CLOSEPAREN,    
            COMMA_OR_SEMICOL,       
            EXPRESSION,             
            IDENTIFIER,             
            INIT,                   
            NO_MAIN,               
            OPENPAREN,  
            OPENCURLY,  
            SEMICOL,    
            STATEMENT,    
            TYPENAME,   
        };

        enum Semantic
        {
            NO_ERROR,
            AMBIGUOUS_OVERLOAD,    
            ARGUMENT_MISMATCH,     
//            CANNOT_OVERLOAD,       
            DIVISION_BY_ZERO,      
            EXIT_TYPE,             
            FPRINTF_NO_STR,        
            INDEX_TYPE,            
            INVALID_CAST,          
            INVALID_OPERAND,       
            LIST_CONST,            
            LVALUE_NEEDED,         
            MAIN_NOT_RECURSIVE,    
            MAIN_NO_OVERLOADS,    
            MAIN_PARAMS_ERROR,     
            MAIN_RETURN_ERROR,     
            MULTIPLY_DEFINED,      
            NESTED_PRINTF_INSERTION,
            NO_BREAK,              
            NO_CONTINUE,           
            OPERAND_TYPES,
            PRINTF_OPCODE,
            RETURN_TYPE,           
            TERNARY_TYPES,         
            UNDEFINED_VAR,         
            UNDEFINED_FUNCTION,    
        };

        static void set(Static error);
        static void msg();
        static std::ostream &msg(Semantic error);
        static size_t count();

    private:
        static bool display();

};

#include "count.f"
#include "set.f"

#endif







