#ifndef TRANSLATOR_FACTORY_H
#define TRANSLATOR_FACTORY_H

#include "ast/AstNode.h"

class Translator;

class TranslatorFactory {
public:
    static TranslatorFactory& getFactory();
    Translator* getTranslator(AstNode* node);

    TranslatorFactory(TranslatorFactory const &)    = delete;
    void operator=(TranslatorFactory const &)       = delete;

private:
    TranslatorFactory();
};

#endif //TRANSLATOR_FACTORY_H
