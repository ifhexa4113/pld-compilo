#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <vector>
#include <string>
#include "ir/IRInstruction.h"

class BasicBlock {
public:
    BasicBlock(std::string label_, BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr);
    ~BasicBlock();

    // Getters
    std::string getLabel() const;
    std::vector<IRInstruction*> getInstructions() const;
    BasicBlock* getExitTrue();
    BasicBlock* getExitFalse();

    // Setters
    void setExitTrue(BasicBlock* exitTrue_);
    void setExitFalse(BasicBlock* exitFalse_);

    // Others
    void addInstruction(IRInstruction* instruction);
    void merge(BasicBlock* otherBlock);

protected:
    std::string label;
    std::vector<IRInstruction*> instructions;
    BasicBlock* exitTrue;
    BasicBlock* exitFalse;
};

#endif //BASIC_BLOCK_H
