#include "BinaryAffection.h"

BinaryAffection::BinaryAffection(AffectionOperator op_, Expression* lexpression_, Expression* rexpression_) :
    Expression(),
    op(op_),
    lexpression(lexpression_),
    rexpression(rexpression_)
{

}

BinaryAffection::~BinaryAffection()
{
    delete lexpression;
    delete rexpression;
}

int BinaryAffection::walkTree()
{
    
}