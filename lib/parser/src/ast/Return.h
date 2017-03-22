#ifndef RETURN_H
#define RETURN_H

#include "AstNode.h"
#include "expression/Expression.h"

class Return : public AstNode
{
public:
    Return(Expression* value_ = nullptr);
    virtual ~Return();

    virtual int walkTree();

protected:
    Expression* value;
};

#endif