#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <vector>
#include <string>
#include <ostream>
#include "ir/IRInstruction.h"

class BasicBlock {
public:
    BasicBlock(std::string label_ = "$$unnamed$$", BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr, JumpType exitJumpType_ = Z);
    ~BasicBlock();

    // Getters
    std::string getLabel() const;
    std::vector<IRInstruction*> getInstructions() const;
    BasicBlock* getExitTrue();
    BasicBlock* getExitFalse();
    JumpType getExitJumpType() const;

    // Setters
    void setExitTrue(BasicBlock* exitTrue_);
    void setExitFalse(BasicBlock* exitFalse_);
    void setExitJumpType(JumpType j);

    // Others
    void addInstruction(IRInstruction* instruction);
    void merge(BasicBlock* otherBlock);
    void print(std::ostream& ost) const;

    enum JumpType {
        Z, N, NZ
    };

protected:
    static int labelCounter;
    std::string label;
    std::vector<IRInstruction*> instructions;
    BasicBlock* exitTrue;
    BasicBlock* exitFalse;
    JumpType exitJumpType;
};

#endif //BASIC_BLOCK_H
