#include "BinaryArithmeticOperation.h"
#include "NullExpression.h"

BinaryArithmeticOperation::BinaryArithmeticOperation(ArithmeticOperator op_, Expression* lExpression_, Expression* rExpression_) :
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

BinaryArithmeticOperation::~BinaryArithmeticOperation()
{
    delete lExpression;
    delete rExpression;
}

int BinaryArithmeticOperation::walkTree()
{
    return 0;
}

ArithmeticOperator BinaryArithmeticOperation::getOperator()
{
    return op;
}

Expression* BinaryArithmeticOperation::getRExpression()
{
    return rExpression;
}

Expression* BinaryArithmeticOperation::getLExpression()
{
    return lExpression;
}