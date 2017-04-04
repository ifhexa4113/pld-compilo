#ifndef PLD_COMPILO_BLOCKDATA_H
#define PLD_COMPILO_BLOCKDATA_H

#include <map>

#include "RegisterInfo.h"
#include "cfg/ir/operand/Register.h"

class BlockData {
public:
    BlockData(std::map<Register*, RegisterInfo> info_, int offset_ = -1);
    ~BlockData();

    RegisterInfo getInfo(Register*);
    int getOffset() const;

    void setOffset(int offset_);

protected:
    std::map<Register*, RegisterInfo> info;
    int offset;
};


#endif //PLD_COMPILO_BLOCKDATA_H
