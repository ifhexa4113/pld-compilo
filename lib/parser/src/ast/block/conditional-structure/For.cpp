#include "For.h"
#include "ast/expression/NullExpression.h"

For::For(Expression* condition_, Expression* initialization_, Expression* increment_) :
        ConditionalStructure(condition_),
        initialization(initialization_),
        increment(increment_)
{
    if(initialization == nullptr)
    {
        initialization = new NullExpression();
    }
    if(increment == nullptr)
    {
        increment = new NullExpression();
    }
}

For::~For()
{
    delete initialization;
    delete increment;
}

int For::walkTree()
{
    return 0;
}

Expression * For::getInitialization()
{
    return initialization;
}

Expression * For::getIncrement()
{
    return increment;
}