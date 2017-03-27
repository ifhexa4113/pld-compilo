#ifndef AST_H
#define AST_H

#include "AstIterator.h"
#include "block/CmmProgram.h"

class Ast
{
public:
    CmmProgram& getProgram() { return root; };
    AstIterator iterator() const { return AstIterator(this); };

protected:
    CmmProgram root;
};

#endif