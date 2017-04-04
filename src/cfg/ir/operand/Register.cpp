#include "Register.h"
#include <sstream>
#include <utility>

unsigned int Register::nextRegister = 0;

void swap(Register &reg1, Register &reg2)
{
    std::swap(reg1.value, reg2.value);
    std::swap(reg1.name, reg2.name);
}

Register::Register(std::string name_, int value_) :
    Operand(value_), name(name_)
{
    // Nothing else to do
}

Register::Register(int value_) :
    Operand(value_),
    name(([]() {
        std::stringstream ss;
        ss << "%reg" << Register::nextRegister++;
        return ss.str();
    })())
{
    // Nothing else to do
}

Register::Register(Register const &other) :
    Operand(other.value), name(other.name)
{
    // Nothing else to do
}

Register::Register(Register &&other) : Register()
{
    swap(*this, other);
}

Register& Register::operator=(Register reg)
{
    swap(*this, reg);
    return *this;
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