#ifndef BINARY_AFFECTION_OPERATION_TRANSLATOR_H
#define BINARY_AFFECTION_OPERATION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/BinaryAffectionOperation.h"

class BinaryAffectionOperationTranslator : public Translator
{
public:
    BinaryAffectionOperationTranslator(BinaryAffectionOperation* binaryAffectionOperation, CFG* cfg);
    ~BinaryAffectionOperationTranslator();
    SubGraph* translate(Table* table = nullptr);
};

#endif //BINARY_AFFECTION_OPERATION_TRANSLATOR_H