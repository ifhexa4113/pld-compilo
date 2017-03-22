#include "UnaryBinaryOperationOnVariable.h"

UnaryBinaryOperationOnVariable::UnaryBinaryOperationOnVariable(UnaryBinaryOperator op_, LValueExpression* variable_) :
    UnaryBinaryOperation(op_),
    variable(variable_)
{

}

UnaryBinaryOperationOnVariable::~UnaryBinaryOperationOnVariable()
{
    delete variable;
}

int UnaryBinaryOperationOnVariable::walkTree()
{

}