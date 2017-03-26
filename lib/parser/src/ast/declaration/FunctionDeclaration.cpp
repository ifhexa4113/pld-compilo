#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration(std::string name_, Type type_, int nbArgs_) :
    Declaration(name_, type_),
    nbArgs(nbArgs_)
{
    // Nothing else to do
}

FunctionDeclaration::~FunctionDeclaration()
{
    // Nothing else to do
}

int FunctionDeclaration::getNbArgs()
{
    return nbArgs;
}

int FunctionDeclaration::walkTree()
{
    return 0;
}

FunctionDefinition * FunctionDeclaration::toEmptyDefinition()
{
    return new FunctionDefinition(this);
}