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
    std::string getName() const;
    Declaration* getDeclaration();
    Type getType();

protected:
    std::string name;
    Declaration* declaration;
};

#endif //DEFINITION_H
