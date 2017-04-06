#ifndef PLD_COMPILO_FORTRANSLATOR_H
#define PLD_COMPILO_FORTRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/block/conditional-structure/For.h"

class ForTranslator : public Translator
{
public:
    ForTranslator(For* f, CFG* cfg);
    ~ForTranslator();
    SubGraph* translate(Table* table = nullptr);
};

#endif //PLD_COMPILO_FORTRANSLATOR_H
