#include "BinaryArithmetic.h"

BinaryArithmetic::BinaryArithmetic(ArithmeticOperator op_, Expression* lexpression_, Expression* rexpression_) : 
    op(op_),
    lexpression(lexpression_),
    rexpression(rexpression_)
{

}

BinaryArithmetic::~BinaryArithmetic()
{
    delete lexpression;
    delete rexpression;
}

int BinaryArithmetic::walkTree()
{

}