#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Type.h"
#include "LValueDeclaration.h"
#include "ast/definition/VariableDefinition.h"

class VariableDeclaration : public LValueDeclaration
{
public:
    VariableDeclaration(std::string name, Type type);
    ~VariableDeclaration();
    int walkTree();
    VariableDefinition* toEmptyDefinition();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};
};

#endif
