
#ifndef PLD_COMPILO_BINARYARITHMETICOPERATIONTRANSLATOR_H
#define PLD_COMPILO_BINARYARITHMETICOPERATIONTRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/BinaryArithmeticOperation.h"

class BinaryArithmeticOperationTranslator : public Translator
{
public:
    BinaryArithmeticOperationTranslator(BinaryArithmeticOperation* binaryArithmeticOperation, CFG* cfg);
    ~BinaryArithmeticOperationTranslator();
    SubGraph* translate(Table* table = nullptr);
};

#endif //PLD_COMPILO_BINARYARITHMETICOPERATIONTRANSLATOR_H
