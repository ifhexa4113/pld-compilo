#include <iostream>

#include "BinaryAffection.h"

BinaryAffection::BinaryAffection(AffectionOperator op_, LValueExpression* lvalue_, Expression* rexpression_) :
    Expression(),
    op(op_),
    lvalue(lvalue_),
    rexpression(rexpression_)
{

}

BinaryAffection::~BinaryAffection()
{
    delete lvalue;
    delete rexpression;
}

int BinaryAffection::walkTree()
{
    lvalue->walkTree();
    switch(op)
    {
    case AffectionOperator::MINUS_EQUAL: std::cout << " -= "; break;
    default: std::cout << " ERROR ";
    }
    rexpression->walkTree();
    std::cout << std::endl;
    return 0;
}