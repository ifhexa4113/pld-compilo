#ifndef UNARYBINARYOPERATIONONEXPRESSIONTRANSLATOR_H
#define UNARYBINARYOPERATIONONEXPRESSIONTRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/UnaryBinaryOperationOnExpression.h"

class UnaryBinaryOperationOnExpressionTranslator : public Translator
{
public:
    UnaryBinaryOperationOnExpressionTranslator(UnaryBinaryOperationOnExpression* unBinOpE, CFG* cfg);
    ~UnaryBinaryOperationOnExpressionTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //UNARYBINARYOPERATIONONEXPRESSIONTRANSLATOR_H
