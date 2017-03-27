#include "TranslatorFactory.h"
#include "Translator.h"

#include "ast/block/Block.h"
#include "ast/block/CmmProgram.h"
#include "ast/definition/Definition.h"
#include "ast/definition/FunctionDefinition.h"
#include "ast/definition/VariableDefinition.h"
#include "ast/expression/Expression.h"
#include "ast/expression/Expression.h"

TranslatorFactory& TranslatorFactory::getFactory()
{
    static TranslatorFactory tf;
    return tf;
}

TranslatorFactory::TranslatorFactory()
{
    // Nothing else to do
}

Translator* TranslatorFactory::getTranslator(AstNode* node)
{
    // TODO: not fully implemented yet !
    // TODO: put each big part in a small method ?
    if(dynamic_cast<Block*>(node))
    {
        if(dynamic_cast<CmmProgram*>(node))
        {
            // return new CmmProgramTranslator();
        } else if(dynamic_cast<FunctionDefinition*>(node))
        {
            // return new FunctionDefinitionTranslator();
        }
        // check what type of block it is
    } else if(dynamic_cast<Expression*>(node))
    {
        // check what type of expression it is
//        if(dynamic_cast</*TODO*/>(node))
//        {
//            // return new TODO;
//        }
    } else if(dynamic_cast<Definition*>(node)){
        // check what type definition it is
        if(dynamic_cast<VariableDefinition*>(node))
        {
            // return new VariableDefinitionTranslator();
        }
    } else {
        // check what type of other thing it is
    }
    return nullptr;
}