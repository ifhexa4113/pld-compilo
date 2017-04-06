#ifndef RETURN_INSTRUCTION_TRANSLATOR_H
#define RETURN_INSTRUCTION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/instruction/ReturnInstruction.h"

class ReturnInstructionTranslator : public Translator
{
public:
    ReturnInstructionTranslator(ReturnInstruction* returnInstruction, CFG* cfg);
    ~ReturnInstructionTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //RETURN_INSTRUCTION_TRANSLATOR_H
