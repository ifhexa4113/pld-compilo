#ifndef REGISTER_H
#define REGISTER_H

#include <string>

class Register {
public:
    Register(std::string name_, unsigned int value_);
    Register(Register const & other);
    ~Register();
    std::string getName() const;
    int getValue() const;

protected:
    std::string name;
    unsigned int value;
};


#endif //REGISTER_H
