#ifndef VARIABLE_EXPRESSION_TRANSLATOR_H
#define VARIABLE_EXPRESSION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/VariableExpression.h"

class VariableExpressionTranslator : public Translator
{
public:
    VariableExpressionTranslator(VariableExpression* variableExpression, CFG* cfg);
    ~VariableExpressionTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //VARIABLE_EXPRESSION_TRANSLATOR_H