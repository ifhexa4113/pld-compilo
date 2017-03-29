#include "Register.h"

Register::Register(int value_, std::string name_) :
    Operand(value_),name(name_)
{
    // Nothing else to do
}

Register::Register(Register const &other) :
    name(other.name), value(other.value)
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

std::string toString()
{
    return name;
}