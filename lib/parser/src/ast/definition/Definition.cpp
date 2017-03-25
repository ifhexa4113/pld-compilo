#include "Definition.h"

Definition::Definition(std::string name_) :
        AstNode(),
        name(name_)
{
    // Nothing else to do
}

Definition::~Definition()
{
    // Nothing else to do
}

std::string Definition::getName() const
{
    return name;
}