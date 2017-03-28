#include "Register.h"

Register::Register(std::string name_, unsigned int value_) :
    name(name_), value(value_)
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

int Register::getValue() const
{
    return value;
}