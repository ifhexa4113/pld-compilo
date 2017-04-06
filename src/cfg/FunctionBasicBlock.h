#ifndef PLD_COMPILO_FUNCTIONBASICBLOCK_H
#define PLD_COMPILO_FUNCTIONBASICBLOCK_H

#include <vector>
#include "BasicBlock.h"
#include "ast/declaration/LValueDeclaration.h"

class FunctionBasicBlock : public BasicBlock
{
public:
    FunctionBasicBlock(std::string label_ = std::string("%%unnamed%%"), BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr, BasicBlock::JumpType exitJumpType_ = BasicBlock::JumpType::Z)
        : BasicBlock(label_, exitTrue_, exitFalse_, exitJumpType_), args() {};
    ~FunctionBasicBlock() {};

    void setArgs(std::vector<LValueDeclaration*> args_) { args = args_; };
    std::vector<LValueDeclaration*> getArgs() { return args; };

protected:
    std::vector<LValueDeclaration*> args;
};

#endif //PLD_COMPILO_FUNCTIONBASICBLOCK_H
