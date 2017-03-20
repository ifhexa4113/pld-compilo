#include "UnaryBinaryOperationOnVariable.h"

UnaryBinaryOperationOnVariable::UnaryBinaryOperationOnVariable(UnaryBinaryOperator op, Variable* variable) :
    UnaryBinaryOperator(op),
    this->variable(variable)
{

}

UnaryBinaryOperationOnVariable::~UnaryBinaryOperationOnVariable()
{
    delete variable;
}

int UnaryBinaryOperationOnVariable::walkTree()
{

}