#ifndef CFG_H
#define CFG_H

#include <vector>
#include "ast/Ast.h"
#include "BasicBlock.h"

class CFG {
public:
    CFG(Ast* ast_);
    ~CFG();
    void addBasicBlock(BasicBlock* block);
protected:
    Ast* ast;
    std::vector<BasicBlock*> blocks;
};

#endif //CFG_H
