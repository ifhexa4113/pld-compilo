#ifndef IR_INSTRUCTION_H
#define IR_INSTRUCTION_H

class IRInstruction {
public:
    IRInstruction() {};
    virtual ~IRInstruction() {};
    virtual void print() const = 0;
};

#endif //IR_INSTRUCTION_H
