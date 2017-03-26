#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include "ast/AstNode.h"
#include "ast/declaration/Declaration.h"

class Definition : public virtual AstNode
{
public:
    Definition(Declaration* declaration_);
    virtual ~Definition();
    virtual int walkTree() = 0;
    Declaration* getDeclaration();

protected:
    Declaration* declaration;
};

#endif //DEFINITION_H
