#include "ArrayDefinition.h"

ArrayDefinition::ArrayDefinition(std::string name_) :
    Definition(name_)
{
    // Nothing else to do
}

ArrayDefinition::~ArrayDefinition()
{
    // Nothing else to do
}

int ArrayDefinition::walkTree()
{
    return 0;
}