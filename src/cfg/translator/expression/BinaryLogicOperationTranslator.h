#ifndef BINARY_LOGIC_OPERATION_TRANSLATOR_H
#define BINARY_LOGIC_OPERATION_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/BinaryLogicOperation.h"

/**
 *   cfg for different logic expression (in graphviz language)
 *   see http://www.webgraphviz.com/ or doxygen to see representation
 *
 *   digraph {
 *       label="SubGraph of 'a == b'"
 *
 *       input [label="CMP a,b"]
 *       trueBlock [label="reg1 <- 1"]
 *       falseBlock [label="reg1 <- 0"]
 *       output [label="reg1 <- reg1"]
 *
 *       input -> trueBlock[label="True"]
 *       input -> falseBlock[label="False"]
 *
 *       trueBlock -> output[label="True"]
 *       falseBlock -> output[label="True"]
 *   }
 *
 *   digraph {
 *       label="SubGraph of 'expr1 && expr2'"
 *
 *       input [label="CMP expr1->getDestination, 0"]
 *       firstLevelFalseBlock [label="CMP expr2->getDestination, 0"]
 *       secondLevelFalseBlock [label="reg1 <- 1"]
 *       trueBlock [label="reg1 <- 0"]
 *       output [label="reg1 <- reg1"]
 *
 *       input -> trueBlock[label="True (not equal)"]
 *       input -> firstLevelFalseBlock[label="False (equal)"]
 *
 *       firstLevelFalseBlock -> trueBlock [label="True (not equal)"]
 *       firstLevelFalseBlock -> secondLevelFalseBlock [label="False (equal)"]
 *
 *       trueBlock -> output[label="True"]
 *       secondLevelFalseBlock -> output[label="True"]
 *   }
 *
 *   digraph {
 *       label="SubGraph of 'expr1 || expr2'"
 *
 *       input [label="CMP expr1->getDestination, 0"]
 *       firstLevelTrueBlock [label="CMP expr2->getDestination, 0"]
 *       secondLevelTrueBlock [label="reg1 <- 0"]
 *       falseBlock [label="reg1 <- 1"]
 *       output [label="reg1 <- reg1"]
 *
 *       input -> falseBlock[label="False (equal)"]
 *       input -> firstLevelTrueBlock[label="True (not equal)"]
 *
 *       firstLevelTrueBlock -> falseBlock [label="False (equal)"]
 *       firstLevelTrueBlock -> secondLevelTrueBlock [label="True (not equal)"]
 *
 *       falseBlock -> output[label="True"]
 *       secondLevelTrueBlock -> output[label="True"]
 *   }
 */

class BinaryLogicOperationTranslator : public Translator
{
public:
    BinaryLogicOperationTranslator(BinaryLogicOperation* binaryLogicOperation, CFG* cfg);
    ~BinaryLogicOperationTranslator();
    SubGraph* translate();
};

#endif // BINARY_LOGIC_OPERATION_TRANSLATOR_H