#include <iostream>
#include "BinaryLogicOperation.h"
#include "NullExpression.h"

#include <algorithm>

BinaryLogicOperation::BinaryLogicOperation(LogicOperator op_, Expression* lExpression_, Expression* rExpression_) :
    Expression(),
    op(op_),
    lExpression(lExpression_),
    rExpression(rExpression_)
{
    if(rExpression == nullptr)
    {
        rExpression = new NullExpression();
    }
    if(lExpression == nullptr)
    {
        lExpression = new NullExpression();
    }
}

BinaryLogicOperation::~BinaryLogicOperation()
{
    delete lExpression;
    delete rExpression;
}

int BinaryLogicOperation::walkTree()
{
    lExpression->walkTree();
    switch(op)
    {
        case LogicOperator::EQUAL:
            std::cout << " == ";
            break;
        case LogicOperator::LESSER:
            std::cout << " < ";
            break;
        case LogicOperator::GREATER:
            std::cout << " > ";
            break;
        case LogicOperator::OR:
            std::cout << " || ";
            break;
        case LogicOperator::AND:
            std::cout << " && ";
            break;
        case LogicOperator::LESSER_EQUAL:
            std::cout << " <= ";
            break;
        case LogicOperator::GREATER_EQUAL:
            std::cout << " >= ";
            break;
        case LogicOperator::NOT_EQUAL:
            std::cout << " != ";
            break;
        default:
            std::cout << " Error ";
    }
    rExpression->walkTree();
    std::cout << std::endl;
    return 0;
}

LogicOperator BinaryLogicOperation::getOperator()
{
    return op;
}

Expression* BinaryLogicOperation::getRExpression()
{
    return rExpression;
}

Expression* BinaryLogicOperation::getLExpression()
{
    return lExpression;
}

void BinaryLogicOperation::fillSymbolTable(SymbolTableStack& stack)
{
    lExpression->fillSymbolTable(stack);
    rExpression->fillSymbolTable(stack);
}

Type BinaryLogicOperation::getType(SymbolTableStack& stack)
{
    Type lType = lExpression->getType(stack);
    if(lType == Type::VOID_T)
    {
        // TODO global flag error
    }

    Type rType = rExpression->getType(stack);
    if(rType == Type::VOID_T)
    {
        // TODO global flag error
    }

    return static_cast<Type>(std::max<int>(static_cast<int>(lType), static_cast<int>(rType)));
}