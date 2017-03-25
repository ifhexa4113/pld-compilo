#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(std::string name_, Type type_) : LValueDeclaration(name_, type_)
{
    // Nothing else to so
}

VariableDeclaration::~VariableDeclaration()
{
    // Nothing else to do
}

int VariableDeclaration::walkTree()
{
    return 0;
}