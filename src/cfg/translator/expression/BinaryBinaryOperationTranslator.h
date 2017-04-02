#ifndef BINARY_BINARY_OPERATION_TRANSLATOR_H
#define BINARY_BINARY_OPERATION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/BinaryBinaryOperation.h"

class BinaryBinaryOperationTranslator : public Translator
{
public:
    BinaryBinaryOperationTranslator(BinaryBinaryOperation* binaryBinaryOperation, CFG* cfg);
    ~BinaryBinaryOperationTranslator();
    SubGraph* translate();
};

#endif // BINARY_BINARY_OPERATION_TRANSLATOR_H