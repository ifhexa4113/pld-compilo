#ifndef PLD_COMPILO_WHILETRANSLATOR_H
#define PLD_COMPILO_WHILETRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/block/conditional-structure/While.h"

class WhileTranslator : public Translator
{
public:
    WhileTranslator(While* wh, CFG* cfg);
    ~WhileTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //PLD_COMPILO_WHILETRANSLATOR_H
