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
    std::string getName() const;
    Declaration* getDeclaration();

protected:
    std::string name;
    Declaration* declaration;
};

#endif //DEFINITION_H
