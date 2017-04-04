#ifndef LITERAL_NUMBER_H    
#define LITERAL_NUMBER_H

#include <cstdint>
#include "Expression.h"

class LiteralNumberExpression : public Expression
{
public:
    LiteralNumberExpression(int64_t value_);
    ~LiteralNumberExpression(){};
    int walkTree();
    int64_t getValue();

    Type getType(SymbolTableStack&);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);

protected:
    int64_t value;
};

#endif