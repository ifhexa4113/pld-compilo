#include "Translator.h"

Translator::Translator(AstNode* node_, CFG* cfg_): node(node_), cfg(cfg_)
{
    // Nothing else to do
}

Translator::~Translator()
{
    // Nothing else to do
}

TranslatorFactory& Translator::getFactory()
{
    return TranslatorFactory::getFactory();
}