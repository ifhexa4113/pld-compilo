#include "BinaryBinaryOperation.h"

BinaryBinaryOperation::BinaryBinaryOperation(BinaryBinaryOperator op_, Expression* lexpression_, Expression* rexpression_) :
    Expression(),
    op(op_),
    lexpression(lexpression_),
    rexpression(rexpression_)
{

}

BinaryBinaryOperation::~BinaryBinaryOperation()
{
    delete lexpression;
    delete rexpression;
}

int BinaryBinaryOperation::walkTree()
{

}