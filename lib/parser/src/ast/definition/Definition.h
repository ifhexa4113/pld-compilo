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
    virtual Declaration* getDeclaration();
    Type getType();
    std::string getName() const;

protected:
    Declaration* declaration;
};

#endif //DEFINITION_H
