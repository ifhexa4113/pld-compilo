#ifndef PLD_COMPILO_REGISTERINFO_H
#define PLD_COMPILO_REGISTERINFO_H

#include <string>

#include "ast/declaration/Type.h"

class RegisterInfo {
public:
    RegisterInfo(Type type_ = Type::VOID_T, int offset_ = -1);
    ~RegisterInfo();

    int getOffset() const;
    Type getType() const;

    void setOffset(int offset_);
    void setType(Type type_);

protected:
    Type type;
    int offset;
};


#endif //PLD_COMPILO_REGISTERINFO_H
