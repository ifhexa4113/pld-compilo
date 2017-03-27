#include "Translator.h"

Translator::Translator(AstNode* node_): node(node_)
{
    // Nothing else to do
}

Translator::~Translator()
{
    // TODO: should the translator really delete the node ?
    delete node;
}

TranslatorFactory& Translator::getFactory()
{
    return TranslatorFactory::getFactory();
}