#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration(std::string name_, Type type_) :
    Declaration(name_, type_)
{

}

FunctionDeclaration::FunctionDeclaration(std::string name_, Type type_, std::vector<LValueDeclaration*> arguments_) :
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

std::vector<LValueDeclaration*>& FunctionDeclaration::getArguments()
{
    return arguments;
}

void FunctionDeclaration::fillAstTrace(std::string& astTrace)
{
    astTrace += "FUNC DECL\n";
}