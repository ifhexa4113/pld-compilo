#include "LiteralNumber.h"

LiteralNumber::LiteralNumber(int value_) : Operand(value_)
{
    // Nothing else to do
}

LiteralNumber::~LiteralNumber()
{
    // Nothing else to do
}

std::string toString()
{
    std::string stringValue = std::to_string(value);
    return stringValue;
}
