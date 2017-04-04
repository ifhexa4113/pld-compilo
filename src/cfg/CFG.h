#ifndef CFG_H
#define CFG_H

#include <vector>
#include <ostream>
#include "ast/Ast.h"
#include "BasicBlock.h"

class CFG
{
public:
    CFG(Ast* ast_);
    ~CFG();
    void print(std::ostream& ost) const;
    BasicBlock* getInput();

protected:
    Ast* ast;
    BasicBlock* input;
};

#endif //CFG_H
