//#define XERR
#include "builtin.ih"

    // builtin functions are called via Parser::function -> Args::builtin

Builtin::Info Builtin::s_builtin[] =
{
                    // e_bool: optional int, {}: no arguments, 
                    // e_null: any # of arguments (may be prefixed and followed
                    //         by required args
    
    // 0                                                                                default opt arg
    { e_int  | e_reg,   { e_str},                  }, // ARG_HEAD,
    { e_int  | e_reg,   { e_str},                  }, // ARG_TAIL,
    { e_int  | e_reg,   { e_str},                  }, // ASCII_INT, 
    { e_str  | e_reg,   { e_int},                  }, // ASCII_STR, 
                        
    // 4                                           
    { e_list | e_reg,   { e_str},                  }, // BACKTICK,
    { e_str  | e_reg,   { e_str,  e_str},          }, // C_BASE,
    { e_str  | e_reg,   { e_str,  e_str},          }, // C_EXT,
    { e_str  | e_reg,   { e_str,  e_str},          }, // C_PATH,
                                             
    // 8                
    { e_str  | e_reg,   { e_int | e_bool,  e_str}, }, // CHDIR,        0 (P_CHECK)
    { e_int  | e_reg,   { e_str},                  }, // CMD_HEAD,
    { e_int  | e_reg,   { e_str},                  }, // CMD_TAIL,
    { e_int  | e_reg,   { e_int},                  }, // ECHO,
                         
    // C                
    { e_str  | e_reg,   { e_int, e_list},          }, // LIST_ELEMENT,
    { e_list | e_reg,   { e_str},                  }, // EVAL,
    { e_int  | e_reg,   { e_int | e_bool, e_str, 
                                          e_null}, }, // EXEC,         0 (P_CHECK)
    { e_int  | e_reg,   { e_int | e_bool,                        
                          e_str, e_str, 
                          e_null, 
                          e_str, e_str},           }, // EXECUTE,      0 (P_CHECK)
                        
    // 10               
    { e_int  | e_reg,   { e_str},                  }, // EXISTS,
    { e_list | e_reg,   { e_str, e_list},          }, // FGETS,
    { e_int  | e_reg,   { e_str, e_null},          }, // FPRINTF,
    { e_str  | e_reg,   { e_str},                  }, // G_BASE,
                                             
    // 14               
    { e_str  | e_reg,   { e_str},                  }, // G_DEXT,
    { e_str  | e_reg,   { e_str},                  }, // G_EXT,
    { e_str  | e_reg,   { e_str},                  }, // G_PATH,
    { e_str  | e_reg,   {},                        }, // GETCH,
                                             
    // 18               
    { e_list | e_reg,   { e_str},                  }, // GETENV,
    { e_int  | e_reg,   {},                        }, // GETPID,
    { e_str  | e_reg,   {},                        }, // GETS,
    { e_int  | e_reg,   {e_list},                  }, // LISTLEN,
                                                              
    // 1C                               
                                // e_null must be an empty set of 
                                // arguments. The last 2 args are 
                                // optional and must then be
                                // e_order and e_str           
    { e_list | e_reg,   {  e_int | e_bool, e_str,
                          e_null, e_order, e_str},  }, // MAKELIST,     1 (O_FILE)
                                      
    { e_int  | e_reg,   {e_null},                   }, // PRINTF,
    { e_int  | e_reg,   { e_str},                   }, // PUTENV,
    { e_list | e_reg,   {  e_int | e_bool, e_str},  }, // STAT,         0 (P_CHECK)
                                             
    // 20               
    { e_str  | e_reg,   { e_int, e_str},            }, // STR_EL,
    { e_int  | e_reg,   { e_str, e_str},            }, // STRFIND,
    { e_str  | e_reg,   { e_str, e_null},           }, // STRFORMAT,
    { e_int  | e_reg,   { e_str},                   }, // STRLEN,
                                             
    // 24               
    { e_str  | e_reg,   { e_str},                   }, // STRLWR,
    { e_str  | e_reg,   { e_str, e_int},            }, // RESIZE,
    { e_list | e_reg,   { e_str, e_str},            }, // STRTOK,
    { e_str  | e_reg,   { e_str},                   }, // STRUPR,
                                             
    // 28               
    { e_str  | e_reg,   { e_str, e_int, e_int},     }, // SUBSTR,
    { e_int  | e_reg,   { e_int | e_bool, e_str},   }, // SYSTEM,       0 (P_CHECK)
    { e_str  | e_reg,   { e_str},                   }, // TRIM,
    { e_str  | e_reg,   { e_str},                   }, // TRIMLEFT,
                                             
    // 2C               
    { e_str  | e_reg,   { e_str},                   }, // TRIMRIGHT,
    { e_int  | e_reg,   { e_str, e_str},            }, // STRCHR,
    { e_int  | e_reg,   {e_list, e_str},            }, // LISTFIND,
    { e_list | e_reg,   {e_list,e_list| e_str},     }, // LISTUNION,
                                             
    // 30               
    { e_list | e_reg,   {e_null},                   }, // LISTCONST,

};

                    // builtin functions needing 1st argcount arg.
unordered_set<Builtin::Function> Builtin::s_argCount =
    { EXEC, EXECUTE, FPRINTF, PRINTF, STRFORMAT, LISTCONST };

