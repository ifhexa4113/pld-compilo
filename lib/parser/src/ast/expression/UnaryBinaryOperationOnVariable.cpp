#include "UnaryBinaryOperationOnVariable.h"
#include "NullExpression.h"

UnaryBinaryOperationOnVariable::UnaryBinaryOperationOnVariable(UnaryBinaryOperator op_, LValueExpression* variable_) :
    UnaryBinaryOperation(op_),
    variable(variable_)
{
    // Nothing else to do
}

UnaryBinaryOperationOnVariable::~UnaryBinaryOperationOnVariable()
{
    delete variable;
}

int UnaryBinaryOperationOnVariable::walkTree()
{
    return 0;
}

LValueExpression* UnaryBinaryOperationOnVariable::getVariable()
{
    return variable;
}