#ifndef NULL_EXPRESSION_H
#define NULL_EXPRESSION_H

#include "Expression.h"

class NullExpression : public Expression
{
public:
    NullExpression();
    ~NullExpression();
    int walkTree();

    Type getType(SymbolTableStack&);
    bool checkNonVoidType(SymbolTableStack&);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};
};

#endif //NULL_EXPRESSION_H