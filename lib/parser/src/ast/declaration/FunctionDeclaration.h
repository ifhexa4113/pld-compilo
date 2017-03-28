#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>
#include "Type.h"
#include "Declaration.h"
#include "LValueDeclaration.h"
#include "ast/definition/FunctionDefinition.h"

class FunctionDeclaration : public Declaration
{
public:
    FunctionDeclaration(std::string name_, Type type_, std::vector<LValueDeclaration*> arguments_);
    ~FunctionDeclaration();
    int walkTree();
    int getNbArgs();
    FunctionDefinition* toEmptyDefinition();

    std::vector<LValueDeclaration*>& getArguments();

protected:
    std::vector<LValueDeclaration*> arguments;
};

#endif
