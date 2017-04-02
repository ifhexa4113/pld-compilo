#ifndef BINARY_LOGIC_OPERATION_TRANSLATOR_H
#define BINARY_LOGIC_OPERATION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/BinaryLogicOperation.h"

class BinaryLogicOperationTranslator : public Translator
{
public:
    BinaryLogicOperationTranslator(BinaryLogicOperation* binaryLogicOperation, CFG* cfg);
    ~BinaryLogicOperationTranslator();
    SubGraph* translate();
};

#endif // BINARY_LOGIC_OPERATION_TRANSLATOR_H