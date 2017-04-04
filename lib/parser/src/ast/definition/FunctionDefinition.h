#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

#include <vector>
#include "Definition.h"
#include "ast/AstNode.h"
#include "ast/block/Block.h"
class FunctionDeclaration;

class FunctionDefinition : public Definition, public Block
{
public:
    FunctionDefinition(FunctionDeclaration* declaration_);
    FunctionDefinition(FunctionDeclaration* declaration_, std::vector<AstNode*> children_);
    ~FunctionDefinition();
    int walkTree();

    void fillSymbolTable(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack){return false;};

};

#endif