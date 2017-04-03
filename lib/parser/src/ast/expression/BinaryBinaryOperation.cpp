#include "BinaryBinaryOperation.h"
#include "NullExpression.h"
#include "ast/ErrorManager.h"

BinaryBinaryOperation::BinaryBinaryOperation(BinaryBinaryOperator op_, Expression* lExpression_, Expression* rExpression_) :
    Expression(),
    op(op_),
    lExpression(lExpression_),
    rExpression(rExpression_)
{
    if(rExpression == nullptr)
    {
        rExpression = new NullExpression();
    }
    if(lExpression == nullptr)
    {
        lExpression = new NullExpression();
    }
}

BinaryBinaryOperation::~BinaryBinaryOperation()
{
    delete lExpression;
    delete rExpression;
}

int BinaryBinaryOperation::walkTree()
{
    return 0;
}

BinaryBinaryOperator BinaryBinaryOperation::getOperator()
{
    return op;
}

Expression* BinaryBinaryOperation::getRExpression()
{
    return rExpression;
}

Expression* BinaryBinaryOperation::getLExpression()
{
    return lExpression;
}

void BinaryBinaryOperation::fillSymbolTable(SymbolTableStack& stack)
{
    lExpression->fillSymbolTable(stack);
    rExpression->fillSymbolTable(stack);
}

Type BinaryBinaryOperation::getType(SymbolTableStack& stack)
{
    Type lType = lExpression->getType(stack);
    Type rType = rExpression->getType(stack);
    return static_cast<Type>(std::max<int>(static_cast<int>(lType), static_cast<int>(rType)));
}

bool BinaryBinaryOperation::checkNonVoidType(SymbolTableStack& stack)
{
    return lExpression->checkNonVoidType(stack) && rExpression->checkNonVoidType(stack);
}