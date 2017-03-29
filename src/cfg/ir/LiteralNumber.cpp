#include "LiteralNumber.h"
#include <sstream>

LiteralNumber::LiteralNumber(int value_) : Operand(value_)
{
    // Nothing else to do
}

LiteralNumber::~LiteralNumber()
{
    // Nothing else to do
}

std::string LiteralNumber::toString()
{
    std::ostringstream stm ;
    stm << value ;
    return stm.str() ;
}
