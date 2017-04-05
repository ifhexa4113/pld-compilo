#include "LiteralNumber.h"
#include <sstream>

void swap(LiteralNumber &ln1, LiteralNumber &ln2)
{
    std::swap(ln1.value, ln2.value);
}

LiteralNumber::LiteralNumber(int value_) : Operand(value_)
{
    // Nothing else to do
}

LiteralNumber::LiteralNumber(LiteralNumber const &other) : Operand(other.value)
{
    // Nothing else to do
}

LiteralNumber::LiteralNumber(LiteralNumber &&other) : Operand()
{
    swap(*this, other);
}

LiteralNumber& LiteralNumber::operator=(LiteralNumber other)
{
    swap(*this, other);
    return *this;
}

LiteralNumber::~LiteralNumber()
{
    // Nothing else to do
}

std::string LiteralNumber::toString() const
{
    std::ostringstream stm;
    stm << "#" << value;
    return stm.str();
}
