#ifndef REGISTER_INSTRUCTION_H
#define REGISTER_INSTRUCTION_H

#include "IRInstruction.h"
#include "Register.h"

class RegisterInstruction : public IRInstruction
{
public:
    IRInstruction(Register* destination_) : IRInstruction(), destination(destination_) {};
    virtual ~IRInstruction() { delete destination; };
    virtual void print(std::ostream& ost) const = 0;
    Register * getDestination() const { return destination; };

protected:
    Register* destination;
};


#endif //REGISTER_INSTRUCTION_H
