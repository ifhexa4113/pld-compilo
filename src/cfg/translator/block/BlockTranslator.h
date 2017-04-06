#ifndef BLOCK_TRANSLATOR_H
#define BLOCK_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/block/Block.h"

class BlockTranslator : public Translator
{
public:
    BlockTranslator(Block* block, CFG* cfg);
    ~BlockTranslator();
    SubGraph* translate(Table* table = nullptr);
};


#endif //BLOCK_TRANSLATOR_H