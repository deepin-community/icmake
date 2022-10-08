//#define XERR
#include "state.ih"


void (State::*State::s_state[][nStates])() 
{
//  Tokens:
// ALL_DONE (unused):
    { 
        0, 0, 0, 0, 0, 0 
    },  
// SPACE:
    {                                       // current state:
        &State::nc<&State::nop>,            // START    
        &State::ws,                         // CONTENT  
        &State::nc<&State::nop>,            // WS       
        &State::nc<&State::nop>,            // NL0      
        &State::nc<&State::nop>,            // NL1      
        &State::nc<&State::nop>             // NLn      
    },                                      
                                            
// TEXT:                                    
    {                                       // current state:
        &State::text,                       // START        -> CONTENT
        &State::text,                       // CONTENT      
        &State::spaceText,                  // WS           -> CONTENT
        &State::lineNrText,                 // NL0          -> CONTENT
        &State::nlText,                     // NL1          -> CONTENT
        &State::nlLineNrText,               // NLn          -> CONTEXT
    },                                      
                                            
// NL:                                      
    {                                       // current state:
        &State::nl0,                        // START        -> NL0
        &State::nl1,                        // CONTENT      -> NL1
        &State::nl1,                        // WS           -> NL1
        &State::nc<&State::nop>,            // NL0          
        &State::nlN,                        // NL1          -> NLn
        &State::nc<&State::nop>,            // NLn      
    },                                      
                                            
// NEXT:                                    
    {                                       // current state:
        &State::filename,                   // START    
        &State::nc<&State::err>,            // CONTENT  
        &State::nlFilename,                 // WS           -> START
        &State::filename,                   // NL0          -> START
        &State::nlFilename,                 // NL1          -> START
        &State::nlFilename,                 // NLn          -> START
    },                                      
                                            
// AT_EOF:                                  
    {                                       // current state:
        &State::hashLine,                   // START    
        &State::nlHashLine,                 // CONTENT      -> START
        &State::nlHashLine,                 // WS           -> START
        &State::hashLine,                   // NL0          -> START
        &State::nlHashLine,                 // NL1          -> START
        &State::nlHashLine,                 // NLn          -> START
    },
};

char const *State::s_stateName[] =
{
    "START",
    "CONTENT",
    "WS",
    "NL0",
    "NL1",
    "NLn",
};








