#ifndef PLD_COMPILO_FUNCTIONBASICBLOCK_H
#define PLD_COMPILO_FUNCTIONBASICBLOCK_H

#include <vector>
#include "BasicBlock.h"

class FunctionBasicBlock : public BasicBlock
{
public:
    FunctionBasicBlock(std::string label_ = std::string("%%unnamed%%"), BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr, BasicBlock::JumpType exitJumpType_ = BasicBlock::JumpType::Z)
        : BasicBlock(label_, exitTrue_, exitFalse_, exitJumpType_), args() {};
    ~FunctionBasicBlock() {};

    void setArgs(std::vector<Register*> args_) { args = args_; };
    std::vector<Register*> getArgs() { return args; };

protected:
    std::vector<Register*> args;
};

#endif //PLD_COMPILO_FUNCTIONBASICBLOCK_H
