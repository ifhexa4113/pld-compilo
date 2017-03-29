#include <iostream>
#include "TranslatorFactory.h"
#include "Translator.h"
#include "CmmProgramTranslator.h"
#include "FunctionDefinitionTranslator.h"

#include "ast/block/Block.h"
#include "ast/block/CmmProgram.h"
#include "ast/definition/Definition.h"
#include "ast/definition/FunctionDefinition.h"
#include "ast/definition/VariableDefinition.h"
#include "ast/expression/Expression.h"
#include "ast/expression/Expression.h"
#include "ast/keyword-instruction/Instruction.h"

using namespace std;

TranslatorFactory& TranslatorFactory::getFactory()
{
    cout << "Gathering factory" << endl;
    static TranslatorFactory tf;
    return tf;
}

TranslatorFactory::TranslatorFactory()
{
    // Nothing else to do
}

Translator* TranslatorFactory::getTranslator(AstNode* node, CFG* cfg)
{
    cout << "TranslatorFactory::getTranslator : Trying to get a Translator..." << endl;
    // TODO: not fully implemented yet !
    // TODO: put each big part in a small method ?
    if(dynamic_cast<Block*>(node))
    {
        cout << "It's a block..." << endl;
        if(CmmProgram* p = dynamic_cast<CmmProgram*>(node))
        {
            cout << "It's a CmmProgram - returning the right translator." << endl;
            return new CmmProgramTranslator(p, cfg);
        } else if(FunctionDefinition* f = dynamic_cast<FunctionDefinition*>(node))
        {
            cout << "It's a FunctionDefinition - returning the right translator." << endl;
            return new FunctionDefinitionTranslator(f, cfg);
        }
        // check what type of block it is
    } else if(dynamic_cast<Expression*>(node))
    {
        // check what type of expression it is
//        if(dynamic_cast</*TODO*/>(node))
//        {
//            // return new TODO;
//        }
    } else if(dynamic_cast<Definition*>(node))
    {
        // check what type definition it is
        if (dynamic_cast<VariableDefinition *>(node)) {
            // return new VariableDefinitionTranslator();
        }
    } else if(dynamic_cast<Instruction*>(node))
    {
        cout << "It's an instruction..." << endl;

    } else {
        // check what type of other thing it is
    }

    cout << "Can't find a translator." << endl;

    return nullptr;
}