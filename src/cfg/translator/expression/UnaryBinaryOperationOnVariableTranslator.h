#ifndef UNARYBINARYOPERATIONONVARIABLETRANSLATOR_H
#define UNARYBINARYOPERATIONONVARIABLETRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/UnaryBinaryOperationOnVariable.h"

class UnaryBinaryOperationOnVariableTranslator : public Translator
{
public:
    UnaryBinaryOperationOnVariableTranslator(UnaryBinaryOperationOnVariable* unBinOpV, CFG* cfg);
    ~UnaryBinaryOperationOnVariableTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //UNARYBINARYOPERATIONONVARIABLETRANSLATOR_H
