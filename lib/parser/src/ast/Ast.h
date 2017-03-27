#ifndef AST_H
#define AST_H

#include "block/CmmProgram.h"

class Ast
{
public:
    CmmProgram& getProgram() { return root; };

protected:
    CmmProgram root;
};

#endif //AST_H