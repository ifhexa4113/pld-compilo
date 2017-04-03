#include "UnaryBinaryOperationOnExpression.h"
#include "NullExpression.h"
#include "ast/ErrorManager.h"

UnaryBinaryOperationOnExpression::UnaryBinaryOperationOnExpression(UnaryBinaryOperator op_, Expression* expression_) :
    UnaryBinaryOperation(op_),
    expression(expression_)
{
    if(expression == nullptr)
    {
        expression = new NullExpression();
    }
}

UnaryBinaryOperationOnExpression::~UnaryBinaryOperationOnExpression()
{
    delete expression;
}

int UnaryBinaryOperationOnExpression::walkTree()
{
    return 0;
}

Expression* UnaryBinaryOperationOnExpression::getExpression()
{
    return expression;
}

void UnaryBinaryOperationOnExpression::fillSymbolTable(SymbolTableStack& stack)
{
    expression->fillSymbolTable(stack);
}

Type UnaryBinaryOperationOnExpression::getType(SymbolTableStack& stack)
{
    Type type = expression->getType(stack);
    return type;
}

 bool UnaryBinaryOperationOnExpression::checkNonVoidType(SymbolTableStack& stack)
 {
     return expression->checkNonVoidType(stack);
 }