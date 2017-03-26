#include "Definition.h"

Definition::Definition(Declaration* declaration_) :
    AstNode(),
    declaration(declaration_)
{
    // Nothing else to do
}

Definition::~Definition()
{
    if(declaration != nullptr)
    {
        delete declaration;
    }
    declaration = nullptr;
}

std::string Definition::getName() const
{
    return declaration->getName();
}

Declaration * Definition::getDeclaration()
{
    return declaration;
}