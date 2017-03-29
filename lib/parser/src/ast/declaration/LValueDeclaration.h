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
    virtual LValueDeclaration* clone() const
    { return new LValueDeclaration( *this ); }
    virtual int walkTree() = 0;
    virtual Definition* toEmptyDefinition() = 0;
};

#endif
