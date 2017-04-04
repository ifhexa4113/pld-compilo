#ifndef RETURN_H
#define RETURN_H

#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class ReturnInstruction : public AstNode
{
public:
    ReturnInstruction(Expression* value_);
    ~ReturnInstruction();
    int walkTree();
    Expression* getValue() const;

    void fillSymbolTable(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack);

protected:
    Expression* value;
};

#endif