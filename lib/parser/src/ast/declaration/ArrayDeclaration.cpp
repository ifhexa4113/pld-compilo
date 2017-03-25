#include "ArrayDeclaration.h"

ArrayDeclaration::ArrayDeclaration(std::string name_, Type type_, int size_) :
    LValueDeclaration(name_, type_),
    size(size_)
{
    // Nothing else to so
}

ArrayDeclaration::~ArrayDeclaration()
{
    // Nothing else to do
}

int ArrayDeclaration::getSize()
{
    return size;
}

int ArrayDeclaration::walkTree()
{
    return 0;
}