#include "Operand.h"

Operand::Operand(int value_) : value(value_)
{
    // Nothing else to do
}

Operand::~Operand()
{
    // Nothing else to do
}

int Operand::getValue() {
    return value;
}

std::ostream& operator<<(std::ostream& os, const Operand& op)
{
    os << op.toString();
    return os;
}