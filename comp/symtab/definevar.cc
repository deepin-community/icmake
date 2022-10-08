#define XERR
#include "symtab.ih"

// d_var: each nesting level has its own entry. 
//  Level 0: global vars, level 1: parameters, level > 1: local vars
// at each level there is a vector<Var> containing the definitions of
// the variables: name, varType and location. 
// location of:
//  * global variables: their index in the global vector<Var>;
//  * parameters: their index in the parameters vector<Var> + 0xc002
//  * local variabless: 0xc000 - their index in d_locals, which is an array
//      collecting all local variable types.
//
// see also README.stackframe

SemVal Symtab::defineVar(ExprType type, string const &name)
{
    auto &variables = d_var.back(); // the variables at the current 
                                    // nestingLevel: the most recent VarVect

    if (                                    // if name is defined at this 
        int idx = find(variables, name);    // nestingLevel: error, existing   
        idx != -1                           // name
    )
    {
        Error::msg(Error::MULTIPLY_DEFINED) << name << "'\n";
        return { type | e_var, 0 };     // return pseudo variable
    }

    int varIndex = variables.size();    // the newly defined variable's index

    switch (d_var.size())               // select the variable's nesting level
    {
        case 1:                         // for global variables the varIndex
        break;                          // is already OK

        case 2:                         // for parameters: >= 0xc002
            varIndex += 0xc000 + 2;       // see README.stackframe
        break;

        default:                        // for local variables: < 0xc000
            d_locals.push_back(type);
            varIndex = 0xc000 - d_locals.size();
        break;
    }

// xerr("defining " << name << " at location " << hex << 
//       as<uint16_t>(varIndex) << dec << ' ' << as<short>(varIndex));
 
    variables.push_back({ name, type | e_var, as<uint16_t>(varIndex) });

    return { type | e_var, varIndex };  // return the variable's index:
                                // non-negative values: global variables
                                // negative values: parameters or locals
}



