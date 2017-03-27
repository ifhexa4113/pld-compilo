#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>
#include "Type.h"
#include "Declaration.h"
#include "ast/definition/FunctionDefinition.h"

class FunctionDeclaration : public Declaration
{
public:
    FunctionDeclaration(std::string name_, Type type_, std::vector<Declaration*> arguments_);
    ~FunctionDeclaration();
    int walkTree();
    int getNbArgs();
    FunctionDefinition* toEmptyDefinition();

    std::vector<Declaration*>& getArguments();

protected:
    std::vector<Declaration*> arguments;
};

#endif
