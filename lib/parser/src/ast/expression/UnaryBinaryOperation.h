#ifndef UNARY_BINARY_OPERATION_H
#define UNARY_BINARY_OPERATION_H

#include "Expression.h"

enum class UnaryBinaryOperator 
{
    NOT = 0,            // !Expr
    INCREMENT_RIGHT,    // L_value++
    DECREMENT_RIGHT,    // L_value--
    INCREMENT_LEFT,     // ++L_value
    DECREMENT_LEFT,     // --L_value
    MINUS,              // -Expr
    BINARY_NOT          // ~Expr
};

class UnaryBinaryOperation : public Expression
{
public:
    UnaryBinaryOperation(UnaryBinaryOperator op_) : Expression(), op(op_) {};
    virtual int walkTree() = 0;
    virtual void fillSymbolTable(SymbolTableStack& stack) = 0;

protected:
    UnaryBinaryOperator op;
};

#endif