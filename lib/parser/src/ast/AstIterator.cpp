#include "AstIterator.h"

AstIterator::AstIterator(Ast *ast_) : ast(ast_), position(0)
{
    // Nothing else to do
}

AstIterator::~AstIterator()
{
    // Nothing else to do
}

bool AstIterator::hasNext() const
{
    return position + 1 < ast->getProgram().getChildren().size();
}

AstNode * AstIterator::next() const
{
    return ast->getProgram().getChildren()[++position];
}