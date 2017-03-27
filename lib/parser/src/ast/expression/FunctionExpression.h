#ifndef FUNCTION_EXPRESSION_H
#define FUNCTION_EXPRESSION_H

#include <string>
#include <vector>
#include "Expression.h"

class FunctionExpression : public Expression
{
public:
    FunctionExpression(std::string name_);
    FunctionExpression(std::string name_, std::vector<Expression*> parameters_);
    ~FunctionExpression();
    int walkTree();
    std::string getName();
    std::vector<Expression*> getParameters();

    void fillSymbolTable(SymbolTableStack& stack);

protected:
    std::string name;
    std::vector<Expression*> parameters;
};

#endif
