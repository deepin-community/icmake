////#define XERR
//#include "parser.ih"
//
//SemVal Parser::listConst(Args &args)
//{
//    return args.builtin(Builtin::LISTCONST);
//
//
//    SemVal list{ e_const | e_list };         // the result
//
//    for (auto &semVal: args)                // ensure that all args are string
//    {
//        if (semVal.type() & e_str)
//        {
//            semVal.push();                  // all arguments must be strigns
//            list << semVal;                 // add code to list
//            continue;
//        }
//
//        Error::msg(Error::LIST_CONST);
//        return list;
//    }
//
//    list << Opcode::push_imm << as<short>(args.size());
//    list.callBuiltin(Builtin::LISTCONST, args.size() + 1);
//    
//    return 
//    return list;
//}
