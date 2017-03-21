#ifndef AST_H
#define AST_H

#include "CmmProgram.h"

class Ast
{
public:

    CmmProgram& getProgram() const { return root; };

protected:
    CmmProgram* root;
};

#endif