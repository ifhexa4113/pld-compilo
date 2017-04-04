#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ast/AstNode.h"
#include "ast/SymbolTableStack.h"
#include "ast/declaration/Type.h"

class Expression : public AstNode
{
public:
    Expression() {};
    virtual ~Expression() {};
    virtual int walkTree() = 0;
    virtual void fillSymbolTable(SymbolTableStack&){};

    virtual Type getType(SymbolTableStack& stack) = 0;
    virtual bool checkNonVoidType(SymbolTableStack& stack) = 0;
};

#endif