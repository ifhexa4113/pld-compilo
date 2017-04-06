#ifndef LVALUE_H
#define LVALUE_H

#include <string>
#include "Type.h"
#include "Declaration.h"
#include "ast/definition/Definition.h"

class LValueDeclaration : public Declaration
{
public:
    LValueDeclaration(std::string name, Type type);
    virtual ~LValueDeclaration();
    virtual int walkTree() = 0;
    virtual Definition* toEmptyDefinition() = 0;
    bool checkReturnType(Type, SymbolTableStack&){return false;};
};

#endif
