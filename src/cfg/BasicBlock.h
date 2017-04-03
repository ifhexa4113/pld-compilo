#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <vector>
#include <string>
#include <ostream>
#include "ir/IRInstruction.h"

class BasicBlock {
public:
    enum class JumpType {
        Z, N, NZ
    };

    BasicBlock(std::string label_ = "$$unnamed$$", BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr, BasicBlock::JumpType exitJumpType_ = BasicBlock::JumpType::Z);
    ~BasicBlock();

    // Getters
    std::string getLabel() const;
    std::vector<IRInstruction*> getInstructions() const;
    BasicBlock* getExitTrue();
    BasicBlock* getExitFalse();
    BasicBlock::JumpType getExitJumpType() const;

    // Setters
    void setExitTrue(BasicBlock* exitTrue_);
    void setExitFalse(BasicBlock* exitFalse_);
    void setExitJumpType(BasicBlock::JumpType j);

    // Others
    void addInstruction(IRInstruction* instruction);
    void merge(BasicBlock* otherBlock);
    void print(std::ostream& ost) const;
    bool isColored();
    void setColored();

protected:
    static int labelCounter;
    std::string label;
    std::vector<IRInstruction*> instructions;
    BasicBlock* exitTrue;
    BasicBlock* exitFalse;
    BasicBlock::JumpType exitJumpType;
    bool colored = false;
};

#endif //BASIC_BLOCK_H
