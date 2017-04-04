#include <iostream>
#include "BinaryAffectionOperation.h"
#include "NullExpression.h"

BinaryAffectionOperation::BinaryAffectionOperation(AffectionOperator op_, LValueExpression* lvalue_, Expression* rExpression_) :
    Expression(),
    op(op_),
    lvalue(lvalue_),
    rExpression(rExpression_)
{
    if(rExpression == nullptr)
    {
        rExpression = new NullExpression();
    }
}

BinaryAffectionOperation::~BinaryAffectionOperation()
{
    delete lvalue;
    delete rExpression;
}

int BinaryAffectionOperation::walkTree()
{
    lvalue->walkTree();
    switch(op)
    {
        case AffectionOperator::EQUAL:
            std::cout << " = ";
            break;
        case AffectionOperator::PLUS_EQUAL:
            std::cout << " += ";
            break;
        case AffectionOperator::MINUS_EQUAL:
            std::cout << " -= ";
            break;
        case AffectionOperator::MUL_EQUAL:
            std::cout << " *= ";
            break;
        case AffectionOperator::DIV_EQUAL:
            std::cout << " /= ";
            break;
        case AffectionOperator::MOD_EQUAL:
            std::cout << " %= ";
            break;
        case AffectionOperator::XOR_EQUAL:
            std::cout << " ^= ";
            break;
        case AffectionOperator::OR_EQUAL:
            std::cout << " |= ";
            break;
        case AffectionOperator::AND_EQUAL:
            std::cout << " &= ";
            break;
        default: std::cout << " ERROR ";
    }
    rExpression->walkTree();
    std::cout << std::endl;
    return 0;
}

LValueExpression* BinaryAffectionOperation::getLValue()
{
    return lvalue;
}

AffectionOperator BinaryAffectionOperation::getOperator()
{
    return op;
}

Expression* BinaryAffectionOperation::getRExpression()
{
    return rExpression;
}

void BinaryAffectionOperation::fillSymbolTable(SymbolTableStack& stack)
{
    lvalue->fillSymbolTable(stack);
    rExpression->fillSymbolTable(stack);
}

Type BinaryAffectionOperation::getType(SymbolTableStack& stack)
{
    return lvalue->getType(stack);
}

bool BinaryAffectionOperation::checkNonVoidType(SymbolTableStack& stack)
{
    return rExpression->checkNonVoidType(stack);
}

void BinaryAffectionOperation::fillAstTrace(std::string& astTrace)
{
    astTrace += "BINARY AFFECT\n";
}