#include "If.h"

If::If(Expression* condition_) :
    ConditionalStructure(condition_)
{
    // Nothing else to do
}

If::If(Expression* condition_, std::vector<AstNode*> children_) :
    ConditionalStructure(condition_, children_)
{
    // Nothing else to do
}

If::~If()
{
    // Nothing else to do
}

int If::walkTree()
{
    return 0;
}