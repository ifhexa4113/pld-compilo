#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Type.h"
#include "Declaration.h"
#include "ast/definition/FunctionDefinition.h"
#include <memory>
class FunctionDeclaration : public Declaration
{
public:
    FunctionDeclaration(std::string name, Type type, int nbArgs);
    ~FunctionDeclaration();
    virtual const std::shared_ptr<Declaration> clone() const
    {
        return std::shared_ptr<Declaration>( new FunctionDeclaration(*this));
    }
    int walkTree();
    int getNbArgs();
    FunctionDefinition* toEmptyDefinition();

protected:
    int nbArgs;
};

#endif
