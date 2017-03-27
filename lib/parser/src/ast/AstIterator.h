#ifndef AST_ITERATOR_H
#define AST_ITERATOR_H

#include "ast/Ast.h"
#include "ast/AstNode.h"

class AstIterator
{
public:
    AstIterator(Ast* ast_);
    ~AstIterator();
    bool hasNext() const;
    AstNode* next() const;

protected:
    Ast* ast;
    int position;
};


#endif //AST_ITERATOR_H
