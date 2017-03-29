#include "Register.h"

unsigned int Register::nextRegister = 0;

Register::Register(std::string name_, int value_) :
    Operand(value_), name(name_)
{
    // Nothing else to do
}

Register::Register(int value_) : Operand(value_), name("%reg" + Register::nextRegister++)
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