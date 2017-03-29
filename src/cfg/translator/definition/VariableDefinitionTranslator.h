#ifndef VARIABLE_DEFINITION_TRANSLATOR_H
#define VARIABLE_DEFINITION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/definition/VariableDefinition.h"

class VariableDefinitionTranslator : public Translator
{
public:
    VariableDefinitionTranslator(VariableDefinition* variableDef, CFG* cfg);
    ~VariableDefinitionTranslator();
    SubGraph* translate();
};


#endif //VARIABLE_DEFINITION_TRANSLATOR_H
