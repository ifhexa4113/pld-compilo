#include "Register.h"

Register::Register(int value_, std::string name_) :
    Operand(value_),name(name_)
{
    // Nothing else to do
}

Register::Register(Register const &other) :
    Operand(other.value), name(other.name)
{
    // Nothing else to do
}

Register::~Register()
{
    // Nothing else to do
}

std::string Register::getName() const
{
    return name;
}

std::string Register::toString() const
{
    return name;
}