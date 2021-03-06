#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include "Definition.h"
#include "ast/expression/Expression.h"
#include "ast/declaration/LValueDeclaration.h"

class VariableDefinition : public Definition
{
public:
    VariableDefinition(LValueDeclaration* declaration_, Expression* rExpression_);
    ~VariableDefinition();
    int walkTree();
    Expression* getRExpression();
    LValueDeclaration* getDeclaration() override {
        return dynamic_cast<LValueDeclaration*>(declaration);
    };

    void fillSymbolTable(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};

protected:
    Expression* rExpression;
};

#endif