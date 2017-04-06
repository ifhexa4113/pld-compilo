#include <iostream>
#include "Block.h"

Block::Block() :
    AstNode(),
    children()
{
    // Nothing else to do
}

Block::Block(std::vector<AstNode*> children_) :
    AstNode(),
    children(children_)
{

}

Block::~Block()
{
    for(auto child : children)
    {
        delete child;
    }
}

int Block::walkTree()
{
    std::cout << "Entering Block, exploring its children." << std::endl;
    for(auto child : children)
    {
        child->walkTree();
    }
    return 0;
}

std::vector<AstNode *> Block::getChildren()
{
    return children;
}

SymbolTable Block::getSymbolTable()
{
    return symbolTable;
}

void Block::addChildren(AstNode *child)
{
    children.push_back(child);
}

void Block::fillSymbolTable(SymbolTableStack& stack)
{
    stack.push(symbolTable);
    for(auto child : children)
        child->fillSymbolTable(stack);
    stack.pop();
}

void Block::fillAstTrace(std::string& astTrace)
{
    astTrace += "BLOCK\n";
    for (auto child : children)
        child->fillAstTrace(astTrace);
}

bool Block::checkReturnType(Type type, SymbolTableStack& stack)
{
    bool checkReturn = false;
    for (auto child : children)
    {
        if (child->checkReturnType(type, stack) == true)
        checkReturn = true;
    }
    return checkReturn;
}