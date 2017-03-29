#ifndef FUNCTION_DEFINITION_TRANSLATOR_H
#define FUNCTION_DEFINITION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/definition/FunctionDefinition.h"

class FunctionDefinitionTranslator : public Translator
{
public:
    FunctionDefinitionTranslator(FunctionDefinition* functionDef, CFG* cfg);
    ~FunctionDefinitionTranslator();
    SubGraph* translate();
};


#endif //FUNCTION_DEFINITION_TRANSLATOR_H
