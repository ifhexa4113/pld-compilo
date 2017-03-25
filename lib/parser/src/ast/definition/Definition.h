#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include "ast/AstNode.h"

class Definition : public virtual AstNode
{
public:
    Definition(std::string name_);
    virtual ~Definition();
    virtual int walkTree() = 0;
    std::string getName() const;

protected:
    std::string name;
};

#endif //DEFINITION_H
