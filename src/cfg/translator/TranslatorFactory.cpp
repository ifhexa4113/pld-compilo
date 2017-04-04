#include <iostream>
#include "TranslatorFactory.h"
#include "Translator.h"
#include "block/CmmProgramTranslator.h"
#include "block/WhileTranslator.h"
#include "block/ForTranslator.h"
#include "definition/VariableDefinitionTranslator.h"
#include "definition/FunctionDefinitionTranslator.h"
#include "instruction/ReturnInstructionTranslator.h"

#include "expression/LiteralNumberTranslator.h"
#include "expression/BinaryArithmeticOperationTranslator.h"
#include "expression/BinaryBinaryOperationTranslator.h"
#include "expression/FunctionExpressionTranslator.h"
#include "expression/VariableExpressionTranslator.h"

#include "ast/expression/Expression.h"
#include "ast/expression/LiteralNumberExpression.h"
#include "ast/expression/BinaryBinaryOperation.h"
#include "ast/expression/BinaryArithmeticOperation.h"
#include "ast/expression/ParenthesisExpression.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/expression/VariableExpression.h"

#include "ast/block/Block.h"
#include "ast/block/CmmProgram.h"
#include "ast/block/conditional-structure/While.h"
#include "ast/block/conditional-structure/For.h"
#include "ast/definition/Definition.h"
#include "ast/definition/FunctionDefinition.h"
#include "ast/definition/VariableDefinition.h"
#include "ast/instruction/Instruction.h"
#include "ast/instruction/ReturnInstruction.h"

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
        // check what type of block it is
        cout << "It's a block..." << endl;
        if(CmmProgram* p = dynamic_cast<CmmProgram*>(node))
        {
            cout << "It's a CmmProgram - returning the right translator." << endl;
            return new CmmProgramTranslator(p, cfg);
        } else if(FunctionDefinition* f = dynamic_cast<FunctionDefinition*>(node))
        {
            cout << "It's a FunctionDefinition - returning the right translator." << endl;
            return new FunctionDefinitionTranslator(f, cfg);
        } else if(While* wh = dynamic_cast<While*>(node))
        {
            cout << "It's a While - returning the right translator." << endl;
            return new WhileTranslator(wh, cfg);
        } else if(For* f = dynamic_cast<For*>(node))
        {
            cout << "It's a For - returning the right translator." << endl;
            return new ForTranslator(f, cfg);
        }
    } else if(dynamic_cast<Expression*>(node))
    {
        cout << "It's an expression..." << endl;
        // check what type of expression it is
        if(LiteralNumberExpression* lne = dynamic_cast<LiteralNumberExpression*>(node))
        {
            cout << "It's a LiteralNumberExpression - returning the right translator." << endl;
            return new LiteralNumberTranslator(lne, cfg);
        }
        else if(BinaryArithmeticOperation* binArOp = dynamic_cast<BinaryArithmeticOperation*>(node))
        {
            cout << "It's a BinaryArithmeticOperation - returning the right translator." << endl;
            return new BinaryArithmeticOperationTranslator(binArOp, cfg);
        }
        else if(BinaryBinaryOperation* binBinOp = dynamic_cast<BinaryBinaryOperation*>(node))
        {
            cout << "It's a BinaryBinaryOperation - returning the right translator." << endl;
            return new BinaryBinaryOperationTranslator(binBinOp, cfg);
        }
        else if(ParenthesisExpression* parenthesis = dynamic_cast<ParenthesisExpression*>(node))
        {
            // TODO EXPRESSION do we need to encapsulate it to a ParenthesisTranslator ?
            cout << "It's a ParenthesisExpression - returning the translator of the expression." << endl;
            return getTranslator(parenthesis->getExpression(), cfg);
        }
        else if(FunctionExpression* fe = dynamic_cast<FunctionExpression*>(node))
        {
            cout << "It's a FunctionExpression - returning the right translator." << endl;
            return new FunctionExpressionTranslator(fe, cfg);
        }
        else if(VariableExpression* varExpr = dynamic_cast<VariableExpression*>(node))
        {
            cout << "It's a VariableExpression - returning the right translator." << endl; 
            return new VariableExpressionTranslator(varExpr, cfg);
        }
    } else if(dynamic_cast<Definition*>(node))
    {
        cout << "It's a definition..." << endl;
        // check what type definition it is
        if (VariableDefinition* vDef = dynamic_cast<VariableDefinition *>(node)) {
            cout << "It's a VariableDefinition - returning the right translator." << endl;
            return new VariableDefinitionTranslator(vDef, cfg);
        }
    } else if(dynamic_cast<Instruction*>(node))
    {
        cout << "It's an instruction..." << endl;
        if (ReturnInstruction* retInstr = dynamic_cast<ReturnInstruction*>(node)) {
            cout << "It's a ReturnInstruction - returning the right translator." << endl;
            return new ReturnInstructionTranslator(retInstr, cfg);
        }
    } else {
        // check what type of other thing it is
    }

    cout << "Can't find a translator." << endl;

    return nullptr;
}