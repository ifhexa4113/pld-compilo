
#ifndef PLD_COMPILO_FUNCTIONEXPRESSIONTRANSLATOR_H
#define PLD_COMPILO_FUNCTIONEXPRESSIONTRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/FunctionExpression.h"

class FunctionExpressionTranslator : public Translator
{
public:
    FunctionExpressionTranslator(FunctionExpression* functionExpression, CFG* cfg);
    ~FunctionExpressionTranslator();
    SubGraph* translate();
};

#endif //PLD_COMPILO_FUNCTIONEXPRESSIONTRANSLATOR_H
