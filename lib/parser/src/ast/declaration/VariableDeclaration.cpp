#include "VariableDeclaration.h"
#include "ast/expression/NullExpression.h"
#include <iostream>

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

VariableDefinition * VariableDeclaration::toEmptyDefinition()
{
    return new VariableDefinition(this, new NullExpression());
}

void VariableDeclaration::fillAstTrace(std::string& astTrace)
{
    astTrace += "VAR DECL\n";
}