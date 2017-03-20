#include "UnaryBinaryOperationOnVariable.h"

UnaryBinaryOperationOnVariable::UnaryBinaryOperationOnVariable(UnaryBinaryOperator op_, VariableExpression* variable_) :
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