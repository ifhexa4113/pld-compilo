#include <iostream>
#include "ReturnInstruction.h"
#include "ast/expression/NullExpression.h"
#include "ast/ErrorManager.h"

ReturnInstruction::ReturnInstruction(Expression* value_) :
    Instruction(),
    value(value_)
{
    if(value == nullptr) {
        value = new NullExpression();
    }
}

ReturnInstruction::~ReturnInstruction()
{
    delete value;
}

int ReturnInstruction::walkTree()
{
    std::cout << "Return node" << std::endl;
    return 0;
}

Expression * ReturnInstruction::getValue() const
{
    return value;
}

void ReturnInstruction::fillSymbolTable(SymbolTableStack& stack)
{
    value->fillSymbolTable(stack);
}

void ReturnInstruction::fillAstTrace(std::string& astTrace)
{
    astTrace += "RETURN\n";
}

bool ReturnInstruction::checkReturnType(Type type, SymbolTableStack& stack)
{
    Type returnType = value->getType(stack);
    bool checkReturn = false;
    if ((returnType == Type::VOID_T && type != Type::VOID_T) || (returnType != Type::VOID_T && type == Type::VOID_T))
    {
        ErrorManager& errorManager = ErrorManager::getInstance();
        errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_RETURN_TYPE, "");
    }
    else 
    {
        checkReturn = true;
    }
    return checkReturn;
}