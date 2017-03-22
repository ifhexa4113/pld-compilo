#include <iostream>

#include "BinaryLogic.h"

BinaryLogic::BinaryLogic(LogicOperator op_, Expression* lexpression_, Expression* rexpression_) :
    Expression(),
    op(op_),
    lexpression(lexpression_),
    rexpression(rexpression_)
{

}

BinaryLogic::~BinaryLogic()
{
    delete lexpression;
    delete rexpression;
}

int BinaryLogic::walkTree()
{
    lexpression->walkTree();
    switch(op)
    {
    case LogicOperator::EQUAL: std::cout << " == "; break;
    default: std::cout << " Error ";
    }
    rexpression->walkTree();
    std::cout << std::endl;
    return 0;
}
