#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration(std::string name_, Type type_, std::vector<Declaration*> arguments_) :
    Declaration(name_, type_),
    arguments(arguments_)
{
    // Nothing else to do
}

FunctionDeclaration::~FunctionDeclaration()
{
    // Nothing else to do
}

int FunctionDeclaration::getNbArgs()
{
    return arguments.size();
}

int FunctionDeclaration::walkTree()
{
    return 0;
}

FunctionDefinition * FunctionDeclaration::toEmptyDefinition()
{
    return new FunctionDefinition(this);
}

std::vector<Declaration*>& FunctionDeclaration::getArguments()
{
    return arguments;
}