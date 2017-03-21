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

}
