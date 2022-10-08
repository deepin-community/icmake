//#define XERR
#include "semval.ih"

void SemVal::constBinary(Opcode::Byte opcode, SemVal const &rhs)
{
    switch (opcode)
    {
        default:                        // to avoid compiler warnings
        break;

        case Opcode::mul:
            d_value *= rhs.value();
        break;

        case Opcode::div:
            if (rhs.value() == 0)
                Error::msg(Error::DIVISION_BY_ZERO) << "/'\n";
            else
                d_value /= rhs.value();
        break;

        case Opcode::mod:
            if (rhs.value() == 0)
                Error::msg(Error::DIVISION_BY_ZERO) << "%'\n";
            else
                d_value %= rhs.value();
        break;

        case Opcode::add:
            if (d_type & e_str)
            {
                catString(rhs);
                return;
            }
            d_value += rhs.value();
        break;

        case Opcode::sub:
            d_value -= rhs.value();
        break;

        case Opcode::eq:
            d_value = constCompare(rhs) == 0;
        break;

        case Opcode::neq:
            d_value = constCompare(rhs) != 0;
        break;

        case Opcode::sm:
            d_value = constCompare(rhs) < 0;
        break;

        case Opcode::gr:
            d_value = constCompare(rhs) > 0;
        break;

        case Opcode::smeq:
            d_value = constCompare(rhs) <= 0;
        break;

        case Opcode::greq:
            d_value = constCompare(rhs) >= 0;
        break;

        // case younger         - only run-time
        // case older

        case Opcode::band:
            d_value &= rhs.value();
        break;

        case Opcode::bor:
            d_value |= rhs.value();
        break;

        case Opcode::bxor:
            d_value ^= rhs.value();
        break;

        case Opcode::shl:
            d_value <<= rhs.value();
        break;

        case Opcode::shr:
            d_value >>= rhs.value();
        break;
    }

    d_type = e_int | e_const;
}

