#ifndef IR_INSTRUCTION_H
#define IR_INSTRUCTION_H

#include <ostream>

class IRInstruction {
public:
    IRInstruction() {};
    virtual ~IRInstruction() {};
    virtual void print(std::ostream& ost) const = 0;
};

#endif //IR_INSTRUCTION_H
