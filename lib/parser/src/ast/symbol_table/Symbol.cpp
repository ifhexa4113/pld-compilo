#include "Symbol.h"

Symbol::Symbol(std::string name_, Type type_, int address_) :
    name(name_),
    type(type_),
    address(address_)
{
    // Nothing else to do
}

Symbol::~Symbol()
{
    // Nothing else to do
}

std::string Symbol::getName()
{
    return name;
}

Type Symbol::getType()
{
    return type;
}

int Symbol::getAddress()
{
    return address;
}