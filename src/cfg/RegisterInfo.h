#ifndef PLD_COMPILO_REGISTERINFO_H
#define PLD_COMPILO_REGISTERINFO_H

#include <string>

#include "ast/declaration/Type.h"

class RegisterInfo {
public:
    RegisterInfo(int offset_ = -1, std::string originalVar_ = "$temp", Type type_ = Type::VOID_T);
    ~RegisterInfo();

    int getOffset() const;
    std::string getOriginalVar() const;
    Type getType() const;

    void setOffset(int offset_);
    void setOriginalVar(std::string originalVar_);
    void setType(Type type_);

protected:
    int offset;
    std::string originalVar;
    Type type;
};


#endif //PLD_COMPILO_REGISTERINFO_H
