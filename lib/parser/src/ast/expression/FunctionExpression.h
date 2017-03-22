#ifndef FUNCTION_EXPRESSION_H
#define FUNCTION_EXPRESSION_H

#include <string>
#include <vector>

#include "Expression.h"

class FunctionExpression : public Expression
{
public:
    FunctionExpression(std::string name_);
    FunctionExpression(std::vector<Expression*> list_, std::string name_);
    virtual ~FunctionExpression();
    virtual int walkTree();
    std::string getName() { return name; };

protected:
    std::vector<Expression*> parameters;
    std::string name;
};

#endif
