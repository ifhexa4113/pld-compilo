#include "BinaryBinaryOperation.h"
#include "NullExpression.h"

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