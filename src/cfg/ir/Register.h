#ifndef REGISTER_H
#define REGISTER_H

#include <string>

class Register: public Operand {
public:
    Register(int value_, std::string name_);
    Register(Register const & other);
    ~Register();
    std::string getName() const;
    int getValue() const;

    std::string toString();

protected:
    std::string name;
};


#endif //REGISTER_H
