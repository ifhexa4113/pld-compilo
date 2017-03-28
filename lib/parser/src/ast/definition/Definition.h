#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include "ast/AstNode.h"
#include "ast/declaration/Type.h"

class Declaration;

class Definition : public virtual AstNode
{
public:
    Definition(Declaration* declaration_);
    virtual ~Definition();
    virtual int walkTree() = 0;
    Declaration* getDeclaration();
    Type getType();

    virtual void fillSymbolTable(SymbolTableStack& stack);

protected:
    Declaration* declaration;
};

#endif //DEFINITION_H
