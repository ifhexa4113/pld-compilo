#ifndef REGISTER_H
#define REGISTER_H

#include "Operand.h"

class Register: public Operand {
public:
    Register(int value_ = 0);
    Register(std::string name_, int value_);
    Register(Register const & other);
    ~Register();
    std::string getName() const;
    //int getValue() const;
    std::string toString() const;

protected:
    std::string name;

    static unsigned int nextRegister;
};


#endif //REGISTER_H
