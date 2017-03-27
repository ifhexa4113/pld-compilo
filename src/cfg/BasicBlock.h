#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <vector>
#include <string>
#include "ir/IRInstruction.h"

class BasicBlock {
public:
    BasicBlock(std::string label_, BasicBlock* exitTrue_ = nullptr, BasicBlock* exitFalse_ = nullptr);
    ~BasicBlock();
    std::vector<IRInstruction*> getInstructions() const;
    std::string getLabel() const;
    void addInstruction(IRInstruction* instruction);
protected:
    std::string label;
    std::vector<IRInstruction*> instructions;
    BasicBlock* exitTrue;
    BasicBlock* exitFalse;
};

#endif //BASIC_BLOCK_H
