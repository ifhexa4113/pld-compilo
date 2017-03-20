#include "Symbol.h"

Symbol::Symbol(std::string name, int address) : name(name), address(address)
{

}

Symbol::~Symbol()
{

}

std::string Symbol::getName()
{
    return name;
}

int Symbol::getAddress()
{
    return address;
}